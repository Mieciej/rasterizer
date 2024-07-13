all: ../rasterizer
rasterizer: main.c line.c defs.h
	cc src/main.c src/line.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o rasterizer -g
