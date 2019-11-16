#ifndef FIGCROSS_H
#define FIGCROSS_H

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <Utility.h>
#include <Figure.h>

class Cross : public Figure{
public:
	Cross(const int width, const int weight, const TypeDef_Color color):Figure(width, width, color){

			Width = width;
			Weight = weight;

			drawCross();
	}

	void DrawFigure(std::vector<unsigned char> & image_vector) override;

	~Cross(){}
private:
	int Width;
	int Weight;

	void drawCross(void);
};

#endif
