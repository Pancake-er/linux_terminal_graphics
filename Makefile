CC=gcc
CFLAGS=-I include -I lib/include -o example.out 

make: example/src/main.c src/graphics.c lib/src/mem_util.c lib/src/time_util.c
	$(CC) $(CFLAGS) example/src/main.c src/graphics.c lib/src/mem_util.c lib/src/time_util.c