#include <Figure.h>

//PUBLIC METHODS

const std::vector<unsigned char> Figure::Get(void) const
{
	return image;
}


//PRIVATE METHODS

bool Figure::drawPixel(const int x, const int y)
{
	if((x>=0)&&(x<width)&&(y>=0)&&(y<width))
	{
		image.at(y * width + x) = 255;
		return true;
	}
	else return false;
}

unsigned char Figure::getPixel(const int x, const int y)
{
	if((x>=0)&&(x<width)&&(y>=0)&&(y<width))
	{
		return image.at(y * width + x);
	}
	else return 0;
}
