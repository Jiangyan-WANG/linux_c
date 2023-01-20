
all:test
	echo "success"

test:add.o sub.o mul.o div.o
	gcc test.c add.o sub.o mul.o div.o -o hello

add.o:add.c
	gcc -c add.c -o add.o

sub.o:sub.c
	gcc -c sub.c -o sub.o

mul.o:mul.c
	gcc -c mul.c -o mul.o

div.o:div.c
	gcc -c div.c -o div.o

clean:
	rm *.o
