#include<stdio.h>
#include<stdlib.h>
#include <err.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Init/pixel_operations.h"
#include "Init/binarize.h"
#include "Init/grey_level.h"
#include "Detection/segmentation.h"
#include "Init/image.h"
#include "xor/xor.h"

int main(int argc, char** argv)
{
    if(argc < 2 ) //not enough arguments
        errx(1, "Wrong argument : please writ of path of the image");
    if(argc > 3)//if they are more than 2 arguments after the ./main
        errx(1, "Too many arguments");
    if (argc == 2 && (strcmp(argv[1], "xor") == 0))
        XOR();
        //if the argument is "xor" launch the xor IA
    if (argc == 3 && (strcmp(argv[1], "image") == 0))
    {
        //if they're 3 arguments and the 2nd is "image", launch the binarization and detection with the 3rd argument
	SDL_Surface* image_surface;
	SDL_Surface* screen_surface;


	image_surface = load_image(argv[2]);
	screen_surface = display_image(image_surface);

	// initialization 

	wait_for_keypressed();

	grey_level(image_surface);
	    
	update_surface(screen_surface, image_surface);

	// change the image in grey color

	wait_for_keypressed();

	binarize(image_surface);
	   
	update_surface(screen_surface, image_surface);

        // binarize the image

	wait_for_keypressed();

	lines(image_surface);

	update_surface(screen_surface, image_surface);

	// do the segmentation of the image

	wait_for_keypressed();

	SDL_FreeSurface (image_surface);
	SDL_FreeSurface (screen_surface);

	// clean the screen and free memory places	
    }
    return 0;
}
