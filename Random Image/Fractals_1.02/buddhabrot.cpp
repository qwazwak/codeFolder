/*
  This program computes the buddhabrot set and outputs to a bitmap
  Under GPL (http://www.gnu.org/licenses/gpl.txt)
  (c) Adrian Neumann 2005

  Posted online at http://easybmp.sourceforge.net by the generous
  permission of Adrian Neumann on September 9, 2005.
*/

#include "EasyBMP.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //to initialize the random generator
    srand(clock());
    //the bitmap
    BMP mandel;
    mandel.SetSize(500,500); //requires quite a lot of ram, adjust for crappy machines
    mandel.SetBitDepth(24);
    //mandel.ReadFromFile("tmp.bmp") in case the computer dies
    //nescessary variables
    double tmp = 0, zr = 0, zi = 0, cr=0, ci=0, l=0;
    int i=0;
	cout << setprecision(12) << fixed << showpoint;
    for (long unsigned int muh=0; muh<4294967295; muh++)
     {
           //2^32 (takes ages, adjust for crappy machines) random points (more==better)
           cr=((double)rand()/RAND_MAX)*4-2;
           ci=((double)rand()/RAND_MAX)*4-2;
           l=0;
           i=0;
           //are tested wether they escape or not
           while (i<=150)
           {
                 tmp=zr*zr-zi*zi+cr;
                 zi=2*zr*zi+ci;
                 zr=tmp;
                 i++;
           }
           l=(zr*zr+zi*zi);
           zr=0;
           zi=0;
           if (!(muh % 1000000)) std:: cout<<(100.0*(static_cast<double>(muh)/4294967295.0))<<std::endl; //progress notification
           if (!(muh % 5000000)) mandel.WriteToFile("tmp.bmp"); //in case the computer dies
           //if they _do_ escape their
           if (l>=4) {
           //trajectories are saved in a bitmap
           while (zr<1 && zr>-2 && zi<1 && zi>-1)
           {
                 //make sure to adjust these numebers if you change the resolution (multiply by same factor)
                 if (mandel((int)(zr*125+250),(int)(zi*125+250))->Blue>3) {
                 mandel((int)(zr*125+250),(int)(zi*125+250))->Blue-=2; 
                 mandel((int)(zr*125+250),(int)(zi*125+250))->Red-=2;
                 mandel((int)(zr*125+250),(int)(zi*125+250))->Green-=2;}
                 tmp=zr*zr-zi*zi+cr;
                 zi=2*zr*zi+ci;
                 zr=tmp;
           } 
           }


     }
    //which is then saved to a file
    mandel.WriteToFile("muh.bmp");
    return 0;
}
