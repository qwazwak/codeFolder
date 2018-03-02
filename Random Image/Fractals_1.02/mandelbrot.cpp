/*
  This program computes the mandelbrot set and outputs to a bitmap.
  Under GPL (http://www.gnu.org/licenses/gpl.txt)
  (c) Adrian Neumann 2005
  
  Posted online at http://easybmp.sourceforge.net by the generous 
  permission of Adrian Neumann on September 9, 2005.
*/

#include "EasyBMP.h"

using namespace std;

int main()
{
    //declare a bitmap
    BMP mandel;
    mandel.SetSize(8001,8001);
    mandel.SetBitDepth(24);
    //initialize variables for the algorithm
    double tmp = 0, zr = 0, zi = 0, l=0;
    int i=0;
    //for every complex number in our plane
    for (double cr=-2; cr<2;cr+=0.0005)
     for (double ci=-2; ci<2; ci+=0.0005)
     {
           //either escapes to inifinty or stays here for 1020 iterations
           while (l<=4 && i<1020)
           {
                 //mandelbrot iteration
                 tmp=zr*zr-zi*zi+cr;
                 zi=2*zr*zi+ci;
                 zr=tmp;
                 l=(zr*zr+zi*zi);
                 i++;
           }
           //write the point nicely colored to the bitmap
           if (i>1) {
           mandel((int)(cr*2000+4000), (int)(ci*2000+4000))->Blue =
(BYTE) ( 255-(i/4));
           mandel((int)(cr*2000+4000), (int)(ci*2000+4000))->Red =
(BYTE) (255-(i*2.5));
           mandel((int)(cr*2000+4000), (int)(ci*2000+4000))->Green =
(BYTE) (255-(i*2.5)); }
           if (i>25) {
           mandel((int)(cr*2000+4000), (int)(ci*2000+4000))->Blue =
(BYTE) (255-(i/4));
           mandel((int)(cr*2000+4000), (int)(ci*2000+4000))->Red =
(BYTE) (255-(i*1.25));
           mandel((int)(cr*2000+4000), (int)(ci*2000+4000))->Green =
(BYTE) (255-(i*1.25)); }
           if (i>250) {
           mandel((int)(cr*2000+4000), (int)(ci*2000+4000))->Blue =
(BYTE) (255-(i/4));
           mandel((int)(cr*2000+4000), (int)(ci*2000+4000))->Red =
(BYTE) (255-(i/4));
           mandel((int)(cr*2000+4000), (int)(ci*2000+4000))->Green =
(BYTE) (255-(i/4)); }
           //reset vars
           l=0;
           i=0;
           zr=0;
           zi=0;
     }
    mandel.WriteToFile("muh.bmp");
    return 0;
}
