CC = gcc
RM = rm -f
SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c,%.o,$(SRCS))
CFLAGS = -Wall `pkg-config --cflags gtk+-2.0`
#CFLAGS = -Wall `pkg-config --cflags gtk+-3.0`
LFLAGS = `pkg-config --libs gtk+-2.0`
#LFLAGS = `pkg-config --libs gtk+-3.0`
TGTS = ex01

all : $(TGTS)

$(TGTS) : $(OBJS)
	$(CC) -o $(TGTS) $(OBJS) $(LFLAGS)

.c.o :
	$(CC) $(CFLAGS) -c $<

clean :
	$(RM) $(TGTS) $(OBJS)
