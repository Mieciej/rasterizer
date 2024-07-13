all: rasterizer
rasterizer: src/main.c src/line.c src/defs.h src/triangle.c
	cc src/main.c src/line.c src/triangle.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o rasterizer -g
