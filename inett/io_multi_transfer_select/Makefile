all: web_server

web_server: wrap.c web_server.c
	gcc $^ -o $@ -pthread

.PHONY:clean

clean:
	rm -rf web_server
