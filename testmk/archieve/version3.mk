OBJS = add.o sub.o mul.o div.o test.o

TARGET = test
CC = gcc

$(TARGET):$(OBJS)
	$(CC) $^ -o $@ 

add.o:add.c
	gcc -c add.c -o add.o

sub.o:sub.c
	gcc -c sub.c -o sub.o

mul.o:mul.c
	gcc -c mul.c -o mul.o

div.o:div.c
	gcc -c div.c -o div.o


test.o:test.c
	gcc -c test.c -o test.o
clean:
	rm -rf $(OBJS) $(TARGET)
