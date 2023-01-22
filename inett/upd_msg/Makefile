all: client server

client: client_u.c
	gcc $< -o $@

server: server_u.c
	gcc $< -o $@

.PHONY:clean

clean:
	rm -rf client server
