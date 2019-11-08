#include <FigCross.h>

void FigCross::Draw(void){
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
