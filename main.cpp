#include "Bitmap/bitmap.h"
#include <iostream>
#include <vector>

using namespace std;

//argc - number of arguments in command
//argv - each argument word, stored in an array
int main(int argc, char* argv[])
{

if(argc!=2)
{
cout<<"Please specify one image file!\n";
}

string filename = argv[1];
Bitmap image;
image.open(filename);


if(image.isImage())
{
  vector < vector <Pixel> > imagePixels = image.toPixelMatrix();  
  cout<<argv[1]<<" is "<<imagePixels.size()<<" pixels high and "<<imagePixels[0].size()<<" pixels wide\n";
  
  for(int row=0; row<imagePixels.size(); row++)
  {
    for(int col=0; col<imagePixels[row].size(); col++)   
    {
      Pixel color;
      color = imagePixels[row][col];
      color.green = 0;
      color.blue = 0;
      imagePixels[row][col] = color;
    }
  }
  image.fromPixelMatrix(imagePixels);
  image.save("redness.bmp");
}
else
{
  cout<<"Image file must be a bitmap with a 24-bit color depth.\n";
}

  return 0;
}

