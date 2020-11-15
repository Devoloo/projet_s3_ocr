# Simple SDL mini Makefile

CC=gcc

CPPFLAGS= `pkg-config --cflags sdl` -MMD
CFLAGS= -Wall -Wextra -Werror -std=c99 -O3
LDFLAGS=
LDLIBS= `pkg-config --libs sdl` -lSDL_image

SRC = main.c Detection/segmentation.c Init/binarize.c Init/pixel_operations.c Init/image.c Init/grey_level.c
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}

all: main

main: ${OBJ}

#main: main.o Detection/segmentation.c Init/binarize.c Init/pixel_operations.c Init/image.c Init/grey_level.c
#main.o: Detection/segmentation.h Init/binarize.h Init/pixel_operations.h Init/image.h Init/grey_level.h

clean:
	${RM} ${OBJ}
	${RM} ${DEP}
	${RM} main

# END
