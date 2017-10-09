CC = $(CROSS_COMPILE)gcc
RM = rm -f
SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c,%.o,$(SRCS))
CFLAGS = -Wall `pkg-config --cflags glib-2.0` -DG_LOG_DOMAIN=\"Test\"
LFLAGS = `pkg-config --libs glib-2.0` -liconv
TGTS = ex66

all : $(TGTS)

$(TGTS) : $(OBJS)
	$(CC) -o $(TGTS) $(OBJS) $(LFLAGS)

.c.o :
	$(CC) $(CFLAGS) -c $<

clean :
	$(RM) $(TGTS) $(OBJS)
