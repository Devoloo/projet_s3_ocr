#ifndef GTK_H
#define GTK_H


#include<stdio.h>
#include<stdlib.h>
#include<err.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<gtk/gtk.h>
#include "../neural/neural_network.h"
#include "../neural/neural_network_tools.h"
#include "../neural/tools.h"
#include "../Init/binarize.h"
#include "../Init/image.h"
#include "../Init/pixel_operations.h"
#include "../Init/grey_level.h"
#include "../Init/noise_reduction.h"
#include "../Init/resize.h"
#include "../Init/increaseChar.h"
#include "../Detection/segmentation.h"

typedef struct
{
	GtkBuilder *builder;
	gpointer user_data;
} SGlobalData;

#define UNUSED(x) (void)(x)

void save_text(GtkButton *button, GtkTextBuffer *buffer);

void load_image(GtkButton *button, GtkImage *image);

int trainNN();

void openFile(GtkButton *button, GtkLabel *text_label);

int launchOCR(GtkButton *button, GtkTextBuffer *buffer);

void create_window(int argc, char *argv[]);

#endif
