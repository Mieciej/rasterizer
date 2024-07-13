all: rasterizer
rasterizer: main.c
	cc main.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o rasterizer -g
