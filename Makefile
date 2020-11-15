# Simple SDL mini Makefile

CC=gcc

CPPFLAGS= `pkg-config --cflags sdl` -MMD
CFLAGS= -Wall -Wextra -Werror -std=c99 -O3
LDFLAGS=
LDLIBS= `pkg-config --libs sdl` -lSDL_image

all: main

main: main.o Detection/segmentation.c Init/binarize.c Init/pixel_operations.c Init/image.c Init/grey_level.c
main.o: Detection/segmentation.h Init/binarize.h Init/pixel_operations.h Init/image.h Init/grey_level.h

clean:
	${RM} *.o
	${RM} *.d
	${RM} main

# END
