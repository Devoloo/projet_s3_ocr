#include <stdio.h>
#include<stdlib.h>
#include <err.h>
#include "binarize.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "pixel_operations.h"

void binarize (SDL_Surface* image_surface)
{
    int width = image_surface->w;
    int height = image_surface->h;
    for(int x=0; x<width; x++)
    {
	for(int y=0;y<height; y++)
	{
	    //for each pixel in the image
	    Uint32 pixel = get_pixel(image_surface,x,y);
	    Uint8 r, g, b;
	    SDL_GetRGB(pixel, image_surface->format, &r, &g, &b);
	    if (r > 127) //all composants are equal so we must just verify one 
	    {
		pixel = SDL_MapRGB(image_surface->format, 255, 255, 255);
		put_pixel(image_surface,x,y,pixel);
		//put the pixel in white if the average if higher than 127
	    }
	    else
	    {	    	
		pixel = SDL_MapRGB(image_surface->format,0,0,0);
		put_pixel(image_surface,x,y,pixel);
		//put the pixel in dark if the average if higher than 127
	    }
	}
    }
}
