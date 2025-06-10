FLS := $(wildcard src/*) asc.xml dsc.xml idea.txt README.md CMakeLists.txt

all: build install lnc

regen:
	mkdir build
	cd build && cmake -G Ninja ..
reconf:
	rm -rf build
	$(MAKE) regen
build:
	@if [ ! -f build/build.ninja ]; then \
	  $(MAKE) regen; \
	fi

	cd build && ninja
install:
	cd build && cp app ..

git:
	git add .
	git commit -m "Updated at $(shell date)"
	git push origin main

lnc:
	wc -l $(FLS)

.PHONY: all regen reconf build install git lnc
