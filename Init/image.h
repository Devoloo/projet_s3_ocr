#ifndef IMAGE_H
#define IMAGE_H

#include<stdlib.h>
#include<stdio.h>
#include<err.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"


SDL_Surface* load_image(char* path);
SDL_Surface* display_image(SDL_Surface *img);
void wait_for_keypressed();
void SDL_FreeSurface(SDL_Surface *surface);

#endif
