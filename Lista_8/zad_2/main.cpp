#include "PPM_to_PGM.h"
int main()
{
    PPM_to_PGM image("obrazek.ppm");
    image.konwertuj();
    image.zapisz("test.pgm");
}

