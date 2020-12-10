#include "gtks.h"

//gchar *filename = "";
//char *text = "";
GtkWidget *parent;
void create_window(int argc, char *argv[])
{
	//Init variables
  GtkWidget *main_window;
	SGlobalData data;
	//Init GTK
	gtk_init(&argc, &argv);
	
	//Build from .glade
  data.builder = gtk_builder_new();
  gtk_builder_add_from_file(data.builder, "main.glade", NULL);
	
	//Get main_window
	main_window =  GTK_WIDGET(gtk_builder_get_object(data.builder,"main_window"));
	
  parent = main_window;
  
	//Connect signals
	gtk_builder_connect_signals(data.builder, &data);

  gtk_window_set_title(GTK_WINDOW(main_window), "OCR");
  gtk_widget_show_all(main_window);
  gtk_main();
}