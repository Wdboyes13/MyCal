CC=gcc
LBCCSRCS = $(wildcard *.c)
LBCNAME = libbc.a
LBCCFLAGS = -I. -I.. -I./../h -Wall -funsigned-char
LBCOBJS = $(patsubst %.c,%.o,$(LBCCSRCS))
AR=ar
RL=ranlib

all: $(LBCNAME)

$(LBCNAME): $(LBCOBJS)
	$(AR) cr $(LBCNAME) $(LBCOBJS)
	$(RL) $(LBCNAME)

%.o: %.c
	$(CC) $(LBCCFLAGS) -c $< -o $@ 
clean:
	rm $(wildcard *.o) $(LBCNAME)

.PHONY: all clean
