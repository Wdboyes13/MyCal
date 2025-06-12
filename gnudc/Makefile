DESTDIR=$(shell pwd)/dist
STRIPPER = strip
all: build
build:
	cd lib && make
	cd dc && make
clean:
	cd lib && make clean
	cd dc && make clean

strip:
	$(STRIPPER) dc/dc
install: strip
	if [ ! -d "$(DESTDIR)" ]; then \
	  mkdir "$(DESTDIR)"; \
	fi

	cp dc/dc $(DESTDIR)/dc

.PHONY: all build clean install strip
