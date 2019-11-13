#include <Utility.h>

bool drawPixel(const int width,
  const int height,
  const int x,
  const int y,
  const Color color,
  std::vector<unsigned char>&image){

	if((x>=0)&&(x<width)&&(y>=0)&&(y<width))
	{
    if((image.at(y * width * 3 + x * 3) + color.r)<255)
		  image.at(y * width * 3 + x * 3) += color.r;
    else image.at(y * width * 3 + x * 3) = 255;

    if((image.at(y * width * 3 + x * 3 + 1) + color.g)<255)
		  image.at(y * width * 3 + x * 3 + 1) += color.g;
    else image.at(y * width * 3 + x * 3 + 1) = 255;

    if((image.at(y * width * 3 + x * 3 + 2) + color.b)<255)
		  image.at(y * width * 3 + x * 3 + 2) += color.b;
    else image.at(y * width * 3 + x * 3 + 2) = 255;

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
		 color_ref.r = image.at(y * width * 3 + x * 3);
		 color_ref.g = image.at(y * width * 3 + x * 3 + 1);
		 color_ref.b = image.at(y * width * 3 + x * 3 + 2);
	}
}
