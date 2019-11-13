#include <Utility.h>

bool drawPixel(const int width,
  const int height,
  const int x,
  const int y,
  const Color color,
  std::vector<unsigned char>&image){

	if((x>=0)&&(x<width)&&(y>=0)&&(y<width))
	{
		image.at(y * width * 3 + x * 3) = color.r;
		image.at(y * width * 3 + x * 3 + 1) = color.g;
		image.at(y * width * 3 + x * 3 + 2) = color.b;
		return true;
	}
	else return false;
}

void getPixel(
  const int width,
  const int height,
  const int x,
  const int y,
  Color & color_ref,
  std::vector<unsigned char>&image){

	if((x>=0)&&(x<width)&&(y>=0)&&(y<width))
	{
		 image.at(y * width * 3 + x) = color_ref.r;
		 image.at(y * width * 3 + x + 1) = color_ref.g;
		 image.at(y * width * 3 + x + 2) = color_ref.b;
	}
}
