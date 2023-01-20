all: readpt  writept

readpt: readpt.c fifo
	gcc $< -o $@

writept:writept.c fifo
	gcc $< -o $@

fifo: mkfifot
	./$< $@

mkfifot: mkfifot.c
	gcc $< -o $@

.PHONY:clean

clean:
	rm -rf fifo mkfifot readpt writept


