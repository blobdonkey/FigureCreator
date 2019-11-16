#include <FigCross.h>

void Cross::drawCross(void){

	for(int y=(width/2)-Weight; y<(width/2)+Weight; y++)
	{
		for(int x=0; x<width; x++) drawPixel(width,height,x,y,color,image_figure);
	}

	for(int x=(width/2)-Weight; x<(width/2)+Weight; x++)
	{
		for(int y=0; y<Width; y++) drawPixel(width,height,x,y,color,image_figure);
	}
}
void Cross::DrawFigure(std::vector<unsigned char> & image_vector){

	image_vector.resize(width * height);

	for(int y = 0; y < width; y++)
	{
		for(int x = 0; x < width; x++)
		{
			getPixel(width,height,x,y,color,image_figure);
			image_vector.at(y * width * 3 + x) = color.r;
			image_vector.at(y * width * 3 + x) = color.g;
			image_vector.at(y * width * 3 + x) = color.b;
		}
	}
}
