all: chat1 chat2

chat1: chat1.c fifo1 fifo2
	gcc $< -o $@

chat2: chat2.c fifo1 fifo2
	gcc $< -o $@

fifo1: mkfifot
	./$< $@

fifo2: mkfifot
	./$< $@

mkfifot: mkfifot.c
	gcc $< -o $@

.PHONY:clean

clean:
	rm -rf mkfifot fifo1 fifo2 chat1 chat2


