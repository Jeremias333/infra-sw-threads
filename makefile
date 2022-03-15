GCC=gcc

.PHONY: run clean

build: ./src/main.c
	gcc $< -o ./src/$@ &

run: 
	src/build

clean:
	rm src/build
