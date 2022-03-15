GCC=gcc

.PHONY: run clean

build: main.c
	gcc $< -o $@ -lpthread &

run: 
	./build

clean:
	rm build
