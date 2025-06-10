FLS := $(wildcard src/*.c) $(wildcard src/*.h) $(wildcard src/rsr/*.c) testing/asc.xml testing/dsc.xml other/idea.txt README.md CMakeLists.txt

all: build tinstall lnc

regen:
	mkdir build
	cd build && cmake -G Ninja .. && cd ..
reconf:
	rm -rf build
	$(MAKE) regen
build:
	@if [ ! -f build/build.ninja ]; then \
	  $(MAKE) regen; \
	fi

	cd build && ninja && cd ..
tinstall:
	cp build/app build/rsr testing/

git:
	git add .
	git commit -m "Updated at $(shell date)"
	git push origin main

lnc:
	wc -l $(FLS)
clean:
	cd other && ./clean.sh
pkg:
	cp build/app build/rsr pkg/
	codesign --sign "Apple Development: wdboyes@icloud.com (5SFDQ6365C)" --force pkg/rsr
	codesign --sign "Apple Development: wdboyes@icloud.com (5SFDQ6365C)" --force pkg/app
	@echo "\n"
	codesign -dvv pkg/app
	@echo "\n"
	zip -r mycal.zip pkg/
.PHONY: all regen reconf build install git lnc clean pkg
