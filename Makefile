# Simple SDL mini Makefile

CC=gcc
CPPFLAGS= `pkg-config --cflags sdl gtk+-3.0` -MMD
CFLAGS= -Wall -Wextra -Werror -std=c99 -O3 -g
LDFLAGS=
LDLIBS= `pkg-config  --libs gtk+-3.0 sdl` -lSDL_image -lm

SRC = main.c Detection/segmentation.c Init/binarize.c Init/pixel_operations.c Init/image.c Init/grey_level.c Init/noise_reduction.c GTK/gtk.c #xor/xor.c
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}

all: main

main: ${OBJ}
xor: ${OBJ}

#main: main.o Detection/segmentation.c Init/binarize.c Init/pixel_operations.c Init/image.c Init/grey_level.c
#main.o: Detection/segmentation.h Init/binarize.h Init/pixel_operations.h Init/image.h Init/grey_level.h

clean:
	${RM} ${OBJ}
	${RM} ${DEP}
	${RM} main

# END
