CC      = clang
CFLAGS  = -Iinclude -Wall -Wextra -Wpedantic -std=c11

TARGET  = app
SRCS    = src/stack.c main.c

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)
