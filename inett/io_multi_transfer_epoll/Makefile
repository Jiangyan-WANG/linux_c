all: web_server e_web_server

web_server: wrap.c web_server.c
	gcc $^ -o $@ -pthread

e_web_server: wrap.c web_server_edgeversion.c
	gcc $^ -o $@ -pthread


.PHONY:clean

clean:
	rm -rf web_server e_web_server a.out
