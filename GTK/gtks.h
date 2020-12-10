#ifndef GTK_H
#define GTK_H


#include<stdio.h>
#include<stdlib.h>
#include<err.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<gtk/gtk.h>

typedef struct
{
	GtkBuilder *builder;
	gpointer user_data;
} SGlobalData;
void create_window(int argc, char *argv[]);

#endif
