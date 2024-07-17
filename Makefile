all: rasterizer
rasterizer: src/main.c src/line.c src/defs.h src/triangle.c src/model.c src/model.h
	cc src/main.c src/line.c src/triangle.c src/model.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o rasterizer -g
clean:
	rm rasterizer
