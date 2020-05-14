#include "PPMimage.h"
int main()
{
    PPM_to_PGM image("obrazek.ppm");
    //image.znieksztalc(20, 50);
    image.zmiekcz();
    image.zapisz("nowy_zm.ppm");
}

