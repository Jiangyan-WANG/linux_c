all:server client

server:servert.c
	gcc $< -o $@

client:clientt.c
	gcc $< -o $@

.PHONY:clean

clean:
	rm -rf client server
