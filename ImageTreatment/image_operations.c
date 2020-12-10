# include "image_operations.h"

/* Transform the image in a greyscale image */
void greyscale(SDL_Surface *image_surface)
{
    int width = image_surface->w;
    int height = image_surface->h;

    for(int x=0; x<width; x++)
    {
        for(int y=0;y<height; y++)
        {
            //for each pixel in the image
            Uint32 pixel = getpixel(image_surface,x,y);
            Uint8 r, g, b;
            SDL_GetRGB(pixel, image_surface->format, &r, &g, &b);
            Uint32 average = 0.3*r + 0.59*g + 0.11*b; //average among CIE 601 recomandation
            pixel = SDL_MapRGB(image_surface->format,average,average,average);
            putpixel(image_surface,x,y,pixel);
            // all composants of the pixel have the same value : the average
        }
    }
}

/* Transform image in Binary Image */
void blacknwhite(SDL_Surface *image_surface)
{
    int width = image_surface->w;
    int height = image_surface->h;
    for(int x=0; x<width; x++)
    {
        for(int y=0;y<height; y++)
        {
            //for each pixel in the image
            Uint32 pixel = getpixel(image_surface,x,y);
            Uint8 r, g, b;
            SDL_GetRGB(pixel, image_surface->format, &r, &g, &b);
            if (r > 127) //all composants are equal so we must just verify one
            {
                pixel = SDL_MapRGB(image_surface->format, 255, 255, 255);
                putpixel(image_surface,x,y,pixel);
                //put the pixel in white if the average if higher than 127
            }
            else
            {
                pixel = SDL_MapRGB(image_surface->format,0,0,0);
                putpixel(image_surface,x,y,pixel);
                //put the pixel in dark if the average if higher than 127
            }
        }
    }
}
/* Noise reduction X4 for the moment...*/
void noiseReduction(SDL_Surface *img)
{
  /* Variables */
  int w;
  int h;
  w = img -> w;
  h = img -> h;
  int pixelTable[5];

 for(int i = 0; i < w; i++)
 {
   for(int j = 0; j < h; j++)
   {
     for(int k = j; k <= j + 4; k++)
     {
       //Borders of picture
       if(i == 0)
       {
         if(k == 0)
         {
            pixelTable[0] = getpixel(img, i, k);
            pixelTable[1] = getpixel(img, i, k);
            pixelTable[2] = getpixel(img, i, k);
            pixelTable[3] = getpixel(img, i, k + 1);
            pixelTable[4] = getpixel(img, i + 1, k);
            break;
         }
         if(k == h)
         {
            pixelTable[0] = getpixel(img, i, k);
            pixelTable[1] = getpixel(img, i, k - 1);
            pixelTable[2] = getpixel(img, i, k);
            pixelTable[3] = getpixel(img, i, k);
            pixelTable[4] = getpixel(img, i + 1, k);
            break;
         }
         else
         {
          pixelTable[0] = getpixel(img, i, k);
          pixelTable[1] = getpixel(img, i, k - 1);
          pixelTable[2] = getpixel(img, i, k);
          pixelTable[3] = getpixel(img, i, k + 1);
          pixelTable[4] = getpixel(img, i + 1, k);
          break;
         }
       }
       if(i == w)
       {
          if(k == 0)
          {
            pixelTable[0] = getpixel(img, i, k);
            pixelTable[1] = getpixel(img, i, k);
            pixelTable[2] = getpixel(img, i - 1, k);
            pixelTable[3] = getpixel(img, i, k + 1);
            pixelTable[4] = getpixel(img, i, k);
            break;
          }
          if(k == h)
          {
            pixelTable[0] = getpixel(img, i, k);
            pixelTable[1] = getpixel(img, i, k - 1);
            pixelTable[2] = getpixel(img, i - 1, k);
            pixelTable[3] = getpixel(img, i, k);
            pixelTable[4] = getpixel(img, i, k);
            break;
          }
          else
          {
            pixelTable[0] = getpixel(img, i, k);
            pixelTable[1] = getpixel(img, i, k - 1);
            pixelTable[2] = getpixel(img, i - 1, k);
            pixelTable[3] = getpixel(img, i, k + 1);
            pixelTable[4] = getpixel(img, i, k);
            break;
          }
       }
       if(k == 0)
       {
          pixelTable[0] = getpixel(img, i, k);
          pixelTable[1] = getpixel(img, i, k);
          pixelTable[2] = getpixel(img, i - 1, k);
          pixelTable[3] = getpixel(img, i, k + 1);
          pixelTable[4] = getpixel(img, i + 1, k);
          break;
       }
       if(k == h)
       {
        pixelTable[0] = getpixel(img, i, k);
        pixelTable[1] = getpixel(img, i, k - 1);
        pixelTable[2] = getpixel(img, i - 1, k);
        pixelTable[3] = getpixel(img, i, k);
        pixelTable[4] = getpixel(img, i + 1, k);
        break;
       }
       else
       {
        pixelTable[0] = getpixel(img, i, k);
        pixelTable[1] = getpixel(img, i, k - 1);
        pixelTable[2] = getpixel(img, i - 1, k);
        pixelTable[3] = getpixel(img, i, k + 1);
        pixelTable[4] = getpixel(img, i + 1, k);
        break;
       }
     }
      array_select_sort(pixelTable, 5);
      int med = pixelTable[2];
      putpixel(img, i, j, med);
   }
 }
}

SDL_Surface* increaseChar(SDL_Surface *img)
{
  SDL_Surface *dest = SDL_CreateRGBSurface(SDL_HWSURFACE,
                        28,
                        28,
                        img->format->BitsPerPixel,0,0,0,0);
  SDL_SoftStretch(img, NULL, dest, NULL);
  return dest;
}
SDL_Surface* Resize(SDL_Surface *img)
{
  SDL_Surface *dest = SDL_CreateRGBSurface(SDL_HWSURFACE,
                        576,
                        460,
                        img->format->BitsPerPixel,0,0,0,0);
  SDL_SoftStretch(img, NULL, dest, NULL);
  return dest;
}
