#include <stdio.h>
#include<stdlib.h>
#include <err.h>
#include "grey_level.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "pixel_operations.h"

void grey_level (SDL_Surface* image_surface)
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
	    Uint32 average = 0.3*r + 0.59*g + 0.11*b; //average among CIE 601 recomandation	
	    pixel = SDL_MapRGB(image_surface->format,average,average,average);
	    put_pixel(image_surface,x,y,pixel); 
	    // all composants of the pixel have the same value : the average   
	}
    }
}    
	
