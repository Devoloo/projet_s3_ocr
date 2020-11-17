#include "main.h"

int main(int argc, char *argv[])
{
    //Argument gesture
    if(argc>1)
    {
        if(strcmp(argv[1], "--XOR") == 0)
        {
            XOR();
        }
        if(strcmp(argv[1], "--OCR") == 0)
        {
            trainNN();
        }
    }
    else
    {
      printf("#-----------------------#\n");
      printf("        Using OCR        \n");
      printf("#-----------------------#\n");
      //Create GTK window
      create_window(argc,argv);
    }
    return(EXIT_SUCCESS);
}
