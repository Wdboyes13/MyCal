DESTDIR=$(shell pwd)/dist
STRIPPER = strip
CC=gcc
AR=ar
RL=ranlib

all: build
build:
	cd lib && make CC=$(CC) AR=$(AR) RL=$(RL)
	cd dc && make CC=$(CC)
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
