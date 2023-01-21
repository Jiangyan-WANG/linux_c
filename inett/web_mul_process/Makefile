all: web_server

web_server: wrap.c web_server.c
	gcc $^ -o $@

.PHONY:clean

clean:
	rm -rf web_server
