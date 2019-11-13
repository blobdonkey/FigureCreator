#include <Primitives.h>

void Point::drawPoint(void){

	if(pStyle == P_SQUARE)
	{
		for(int y=0; y<height; y++)
		{
			for(int x=0; x<width; x++)
			{
				if((x > ((width/2) - pWeight)) && (x < ((width/2) + pWeight)) && ((height/2) > ((height/2) - pWeight)) && (y < ((height/2) + pWeight)))
				{
					drawPixel(width,height,x,y,color,image);
				}
			}
		}
	}
	else
	if(pStyle == P_ROUND)
	{
		for(int y=0; y<height; y++)
		{
			for(int x=0; x<width; x++)
			{
				if(sqrt(pow(x-width/2,2)+pow(y-height/2,2))<pWeight)
				{
					drawPixel(width,height,x,y,color,image);
				}
			}
		}
	}
}
void Point::DrawFigure(std::vector<unsigned char> & image_vector){

	Color color(0,0,0,0);

	image_vector.resize(width * height);

	for(int y = 0; y < width; y++)
	{
		for(int x = 0; x < width; x++)
		{
			getPixel(width,height,x,y,color,image);
			image_vector.at(y * width * 3 + x) = color.r;
			image_vector.at(y * width * 3 + x) = color.g;
			image_vector.at(y * width * 3 + x) = color.b;
		}
	}
}
