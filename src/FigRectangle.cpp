#include <FigRectangle.h>

void Rectangle::drawRectangle(void){

	for(int x=0; x<width; x++)//Balaye les x
	{
		for(int i=0; i<Weight; i++)//Balaye la largeur du trait
		{
			drawPixel(width,height,x,i,color,image_figure);
			drawPixel(width,height,x,height-1-i,color,image_figure);
		}
	}

	for(int y=Weight; y<height-Weight; y++)
	{
		for(int i=0; i<Weight; i++)
		{
			drawPixel(width,height,0+i,y,color,image_figure);
			drawPixel(width,height,width-1-i,y,color,image_figure);
		}
	}
}
void Rectangle::DrawFigure(std::vector<unsigned char> & image_vector){

	image_vector.resize(width * height * 3);

	for(int y = 0; y < width; y++)
	{
		for(int x = 0; x < width; x++)
		{
			getPixel(width,height,x,y,color,image_figure);
			drawPixel(width,height,x,y,color,image_vector);
		}
	}
}
