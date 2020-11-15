#include <err.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "pixel_operations.h"
#include "binarize.h"
#include "segmentation.h"
#include "image.h"

int main(int argc, char** argv)
{
    if(argc < 2 )
	errx(1, "Wrong argument : please writ of path of the image");
    if(argc > 2)
	errx(1, "Too many arguments");
    else
    {
	SDL_Surface* image_surface;
	SDL_Surface* screen_surface;

	init_sdl();

	image_surface = load_image(argv[1]);
	screen_surface = display_image(image_surface);

	// initialization 

	wait_for_keypressed();

	grey_level(image_surface);
	    
	update_surface(screen_surface, image_surface);

	// change the image in grey color

	wait_for_keypressed();

	binarize(image_surface);
	   
	update_surface(screen_surface, image_surface);

        // change the image in black or white

	wait_for_keypressed();

	lines(image_surface);

	update_surface(screen_surface, image_surface);

	// do the segmentation of the image

	wait_for_keypressed();

	SDL_FreeSurface (image_surface);
	SDL_FreeSurface (screen_surface);

	// clean the screen	
    }
    return 0;
}
