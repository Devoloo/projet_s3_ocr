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
#include "Init/noise_reduction.h"
#include "GTK/gtks.h"
#inculde "neural_network.h"

int main(int argc, char** argv)
{
    if(argc > 1 && argc < 3) {
		//if the user write "./main XOR", launch the xor IA
		//if(strcmp(argv[1],"XOR") == 0)
		//	XOR();
		//if the user write "./main OCR", launch the ocr training
		//if(strcmp(argv[1], "OCR") == 0))
		//	TRAIN();
	}
	else {
		printf("---------------------");
		printf("Start to use our OCR !");
		printf("---------------------\n");
		create_window(argc,argv);
	}
	return(EXIT_SUCCESS);
}
