#include <FigSegment.h>

void Segment::drawSegment(void){
	float a = 0.0;
	int Px,Py = 0;

	if((height>0)&&(width>0))
	{
		a = (float)width/height;

		for(int x=0; x<width; x++)
		{
			Py = (int)x/a;
			drawPixel(width,height,x,Py,color,image_figure);
		}

		for(int y=0; y<height; y++)
		{
			Px = (int)y*a;
			drawPixel(width,height,Px,y,color,image_figure);
		}
	}

	if(width==0)//Trait Vertical
	{
		for(int y=0; y<height; y++) drawPixel(1,height,0,y,color,image_figure);
	}

	if(height==0)//Trait Horizontal
	{
		for(int x=0; x<width; x++) drawPixel(width,1,x,0,color,image_figure);
	}
}
void Segment::DrawFigure(std::vector<unsigned char> & image_vector){

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
