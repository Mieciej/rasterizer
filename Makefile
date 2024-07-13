all: rasterizer
rasterizer: main.c line.c defs.h
	cc main.c line.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o rasterizer -g
