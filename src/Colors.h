#ifndef COLORS_H
#define COLORS_H

#include <iostream>

typedef struct
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
}TypeDef_Color;
/*
class Color{
public:
	Color(const int R, const int G, const int B, const int alpha)
	{
		SetColor(R,G,B,alpha);
	}

	void SetColor(const int R, const int G, const int B, const int alpha)
	{
		r = R*((float)alpha/255);
		g = G*((float)alpha/255);
		b = B*((float)alpha/255);
	}

	void printColor(void)
	{
		std::cout<<"("<<r<<","<<g<<","<<b<<")"<<std::endl;
	}

	int r;
	int g;
	int b;
};
*/
#endif
