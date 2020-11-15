#ifndef SEGMENTATION_H
#define SEGMENTATION_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

void lines(SDL_Surface* img);
void columns(SDL_Surface* img, int begin_line, int end_line);

#endif
