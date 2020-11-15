#include <err.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "segmentation.h"
#include "pixel_operations.h"

void columns(SDL_Surface* image, int begin_line, int end_line)
{
	int w = image->w; // the limit of columns
	int end_character = 0; // the end of an encounter with a character
	int begin_black = 0; // first line of the character
	int end_black = 0; // last line of the character
	int white = 0; // if all this column is white
	Uint32 pixel; // variable for a pixel
	Uint8 r, g, b; // variables for the color of the pixel
	int x;
	int y;
	// variables for the loops

	for(x = 0; x < w; x++) // run through of the columns
	{
		white = 1;
		
		for(y = begin_line; y < end_line; y++)
		{
			pixel = get_pixel(image, x, y);
			SDL_GetRGB(pixel, image->format, &r, &g, &b); 
			// get the color of pixel
			
			if(r == 0 && end_character == 0) // first encounter with a character
			{
				end_character = 1; // begin of the character
				begin_black = 1; // must trace the first line
				break;
			}

			if(r == 0) // if the character is not finished
			{
				white = 0;
				break;
			}

			if(b == 255 && end_character == 1 && white == 1 && y == end_line - 1)
			{ // if this is the end of the character with y and if the column is white
				end_character = 0; // the end of the character
				end_black = 1; // must trace the last line
				break;
			}
		}

		if(end_character == 1 && begin_black == 1) // color the first line of the character
		{
			begin_black = 0; 
			for(y = begin_line; y < end_line; y++)
			{
				if(x - 1 > 0) // first line
				{
					pixel = SDL_MapRGB(image->format, 255, 120, 120);
					put_pixel(image, x-1, y, pixel);
					// change in red the color of the first line of the character
				}
			}
		}
		
		if(end_character == 0 && end_black == 1) // color the last line of the character
		{
			end_black = 0;
			for(y = begin_line; y < end_line; y++)
			{
				pixel = SDL_MapRGB(image->format, 255, 120, 120);
				put_pixel(image, x, y, pixel);
				// change in blue the color of the last line of the character
			}
		}
	}
}
			

void lines(SDL_Surface* image)
{
	int w = image->w; // width of img
	int h = image->h; // height of img
	int is_line = 0; // if there is a line, here there is not
	int black = 0; // if the pixel is black, here it's not black
	int begin_line; // coordonate of the beginning of a line with a black pixel
	int end_line; // coordonate of the end of this line
	int x; // variable for loops of the width
	Uint32 pixel; // variable for a pixel
	Uint8 r, g, b; // variables for the color of the pixel

	for(int y = 0; y < h; y++) // run through of the lines
	{
		for(x = 0; x < w; x++) // run through of the columns
		{
			pixel = get_pixel(image, x, y);
			SDL_GetRGB(pixel, image->format, &r, &g, &b); 
			// get the color of pixel
			
			if(r == 0) // if pixel is black
			{
				black = 1;
				break; // exit the loop
			}
		}

		if(black == 1 && is_line == 0) // if line has a black pixel
		{
			is_line = 1; // there is a line
			begin_line = y; // keep the index for the beginning of the line
			
			for(x = 0; x < w; x++)
			{
				pixel = get_pixel(image, x, y);
				int previous = y - 1; // previous line
				if(previous >= 0) // if the height of the previous line is positive
				{
					pixel = SDL_MapRGB(image->format, 120, 120, 255);
					put_pixel(image, x, previous, pixel);
					// change in blue the color of the line
				}
			}
		}
		
		if(black == 0 && is_line == 1) // if previous line had black pixels but now it's white
		{
			is_line = 0; // there is not a line
			end_line = y; // keep the index for the end of the line
			
			for(x = 0; x < w; x++)
			{
				pixel = get_pixel(image, x, y);
				int next = y + 1; // next line
				if(next < h) // if the next line can be reached
				{
					pixel = SDL_MapRGB(image->format, 120, 120, 255);
					put_pixel(image, x, next, pixel);
					// change in blue the color of the line
				}
			}
			columns(image, begin_line, end_line);
			// trace the colums here, because we get the begin and the end of the line
		}
		black = 0; 
	}
}




























