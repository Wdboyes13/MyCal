CC=clang
DCCFLAGS := -I. -I.. -Wall -funsigned-char
DCNAME=dc
DCCSRCS := $(wildcard *.c)
DCOBJS := $(patsubst %.c,%.o,$(DCCSRCS))

all: $(DCNAME)

$(DCNAME): $(DCOBJS)
	$(CC) $(DCCFLAGS) -o $@ $(DCOBJS) -L../lib/ -lbc

%.o: %.c
	$(CC) $(DCCFLAGS) -c $< -o $@

clean:
	rm $(DCNAME) $(wildcard *.o)

.PHONY: all clean
