CC      = clang
CFLAGS  = -Wall -Wextra -O2
LDFLAGS = -framework CoreFoundation

LIB     = libdetectmacmode.dylib
SRCS    = detectmacmode.c
OBJS    = $(SRCS:.c=.o)

.PHONY: all clean

all: $(LIB)

$(LIB): $(OBJS)
	$(CC) -dynamiclib -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(LIB)
