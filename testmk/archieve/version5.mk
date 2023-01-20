#OBJS = add.o sub.o mul.o div.o test.o
SRC = $(wildcard *.c)
OBJS=$(patsubst %.c, %.o, $(SRC))

TARGET = test
CC = gcc
CFLAGS = -c

$(TARGET):$(OBJS)
	$(CC) $^ -o $@ 

%.o:%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@

clean:
	rm -rf $(OBJS) $(TARGET)
