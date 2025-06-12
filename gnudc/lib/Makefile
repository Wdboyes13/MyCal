CC=clang
LBCCSRCS = $(wildcard *.c)
LBCNAME = libbc.a
LBCCFLAGS = -I. -I.. -I./../h  -Wall -Wall -funsigned-char
LBCOBJS = $(patsubst %.c,%.o,$(LBCCSRCS))
AR=ar
RL=ranlib

all: $(LBCNAME)

$(LBCNAME): $(LBCOBJS)
	ar cr $(LBCNAME) $(LBCOBJS)
	$(RL) $(LBCNAME)

%.o: %.c
	$(CC) $(LBCCFLAGS) -c $< -o $@ 
clean:
	rm $(wildcard *.o) $(LBCNAME)

.PHONY: all clean
