all: father child

father: fathert.c
	gcc $< -o $@

child: childt.c
	gcc $< -o $@

.PHONY:clean

clean:
	rm -rf father child
