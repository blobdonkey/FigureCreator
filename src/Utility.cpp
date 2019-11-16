#include <Utility.h>

bool drawPixel(
  const int width,
  const int height,
  const int x,
  const int y,
  const TypeDef_Color color,
  std::vector<unsigned char>&buffer_image){

	if((x>=0)&&(x<width)&&(y>=0)&&(y<height))
	{
    if((buffer_image.at((3*width*y)+(3*x)) + color.r)<255)
		  buffer_image.at((3*width*y)+(3*x)) += color.r;
    else buffer_image.at((3*width*y)+(3*x)) = 255;

    if((buffer_image.at((3*width*y)+(3*x)+1) + color.g)<255)
		  buffer_image.at((3*width*y)+(3*x)+1) += color.g;
    else buffer_image.at((3*width*y)+(3*x)+1) = 255;

    if((buffer_image.at((3*width*y)+(3*x)+2) + color.b)<255)
		  buffer_image.at((3*width*y)+(3*x)+2) += color.b;
    else buffer_image.at((3*width*y)+(3*x)+2) = 255;

		return true;
	}
	else return false;
}

void getPixel(
  const int width,
  const int height,
  const int x,
  const int y,
  TypeDef_Color & color_ref,
  std::vector<unsigned char>&buffer_image){

	if((x>=0)&&(x<width)&&(y>=0)&&(y<height))
	{
		 color_ref.r = buffer_image.at((3*width*y)+(3*x));
		 color_ref.g = buffer_image.at((3*width*y)+(3*x)+1);
		 color_ref.b = buffer_image.at((3*width*y)+(3*x)+2);
	}
}
