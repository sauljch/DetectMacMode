CC      = clang
CFLAGS  = -Wall -Wextra -O2
LDFLAGS = -framework CoreFoundation

PREFIX  = /usr/local
LIB     = libdetectmacmode.dylib
HEADER  = detectmacmode.h
SRCS    = detectmacmode.c
OBJS    = $(SRCS:.c=.o)

.PHONY: all clean install uninstall

all: $(LIB)

$(LIB): $(OBJS)
	$(CC) -dynamiclib -install_name $(PREFIX)/lib/$(LIB) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

install: $(LIB)
	install -d $(PREFIX)/lib $(PREFIX)/include
	install -m 644 $(LIB) $(PREFIX)/lib/$(LIB)
	install -m 644 $(HEADER) $(PREFIX)/include/$(HEADER)

uninstall:
	rm -f $(PREFIX)/lib/$(LIB)
	rm -f $(PREFIX)/include/$(HEADER)

clean:
	rm -f $(OBJS) $(LIB)
