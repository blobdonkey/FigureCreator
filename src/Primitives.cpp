#include <Primitives.h>

void Point::drawPoint(void){

	if(pStyle == P_SQUARE)//Dessine un point carré
	{
		for(int y=0; y<height; y++)
		{
			for(int x=0; x<width; x++)
			{
				if((x > ((width/2) - pWeight)) && (x < ((width/2) + pWeight)) && ((height/2) > ((height/2) - pWeight)) && (y < ((height/2) + pWeight)))
				{
					drawPixel(width,height,x,y,color,image_figure);
				}
			}
		}
	}
	else
	if(pStyle == P_ROUND)//Dessine un point Rond
	{
		for(int y=0; y<height; y++)
		{
			for(int x=0; x<width; x++)
			{
				if(sqrt(pow(x-width/2,2)+pow(y-height/2,2))<pWeight)
				{
					drawPixel(width,height,x,y,color,image_figure);
				}
			}
		}
	}
}
void Point::DrawFigure(std::vector<unsigned char> & image_vector){

	image_vector.resize(width * height);

	for(int y = 0; y < width; y++)
	{
		for(int x = 0; x < width; x++)
		{
			getPixel(width,height,x,y,color,image_figure);
			drawPixel(width,height,x,y,color,image_vector);
		}
	}
}
