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
					image.at((width*y)+x) = pAlpha;
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
				if(sqrt(pow(x-width/2,2)+pow(y-height/2,2))<pWeight) image.at((width*y)+x) = pAlpha;
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
			image_vector.at(y * width + x) = getPixel(x,y);
		}
	}
}
/*
void Point::Draw(void){
	if(pStyle == P_SQUARE)
	{
		for(int y=0; y<height; y++)
		{
			for(int x=0; x<width; x++)
			{
				if((x > (pX - pWeight)) && (x < (pX + pWeight)) && (y > (pY - pWeight)) && (y < (pY + pWeight)))
				{
					image.at((width*y)+x) = 255;
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
				if(sqrt(pow(x-pX,2)+pow(y-pY,2))<pWeight) image.at((width*y)+x) = 255;
			}
		}
	}
}
*/

/*
void Line::Line(
	const int x1,
	const int y,
	const int weight,
	const int style){
		x = pX;
		y = pY;
		weight = pWeight;
		style = pStyle;

		Figure(weight*2-1, weight*2-1);
	}
void Line::Draw(std::vector<char> &image){
	int pX = 0;//Pixel d'abscisses à frapper
	int pY = 0;//Pixel d'ordonnées à frapper

	float dy = (float)y2-y1;
	float dx = (float)x2-x1;

	float a = dy/dx;//Pente de la ligne
	float b = y1-(a*x1);//Offset de la ligne

	if((x2-x1) == 0)
	{
		//Ligne Verticale
		for(int y = y1; (y1<y2) ? (y<=y2) : (y>=y2); y1<y2 ? y++ : y--) drawPixel(x1, y);
	}
	else if((y2-y1) == 0)
	{
		//Ligne Horizontale
		for(int x = x1; (x1<x2) ? (x<=x2) : (x>=x2); x1<x2 ? x++ : x--) drawPixel(x, y1);
	}
	else
	{
		//Balaye les abscisses
		//Les points peuvent êtres placés n'importe où, p1 n'est pas nécessairement inférieur à p2
		for(int x = x1; (x1<x2) ? (x<=x2) : (x>=x2); x1<x2 ? x++ : x--)
		{
			pY = (int)(a*x+b);
			drawPixel(x, pY);//Dessine le pixel
		}

		//Balaye les ordonnées
		//Les points peuvent êtres placés n'importe où, p1 n'est pas nécessairement inférieur à p2
		for(int y = y1; (y1<y2) ? (y<=y2) : (y>=y2); y1<y2 ? y++ : y--)
		{
			pX = (int)((y-b)/a);
			drawPixel(pX, y);//Dessine le pixel
		}
	}
}
*/
