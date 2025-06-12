CC=gcc
DCCFLAGS := -I. -I.. -Wall -funsigned-char
DCNAME=dc
DCCSRCS := $(wildcard *.c)
DCOBJS := $(patsubst %.c,%.o,$(DCCSRCS))
DCLDFLAGS := -L../lib/ -lbc
all: $(DCNAME)

$(DCNAME): $(DCOBJS)
	$(CC) $(DCCFLAGS) -o $@ $(DCOBJS) $(DCLDFLAGS)

%.o: %.c
	$(CC) $(DCCFLAGS) -c $< -o $@

clean:
	rm $(DCNAME) $(wildcard *.o)

.PHONY: all clean
