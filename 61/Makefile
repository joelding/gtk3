CC = $(CROSS_COMPILE)gcc
RM = rm -f
SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c,%.o,$(SRCS))
CFLAGS = -Wall `pkg-config --cflags glib-2.0`
LFLAGS = `pkg-config --libs glib-2.0` -liconv 
TGTS = ex61

all : $(TGTS)

$(TGTS) : $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) -o $(TGTS)
#	$(CC) -o $(TGTS)$(OBJS) $(LFLAGS) 

.c.o :
	$(CC) $(CFLAGS) -c $<

clean :
	$(RM) $(TGTS) $(OBJS)
