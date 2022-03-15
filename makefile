GCC=gcc

.PHONY: run clean

build: main.c
	gcc $< -o $@ &

run: 
	./build

clean:
	rm build
