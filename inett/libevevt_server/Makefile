all: server

server:server.c wrap.c
	gcc $^ -o server -levent

.PHONY:clean

clean:
	rm -rf server
