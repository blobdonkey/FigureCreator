
#ifndef FIGRECTANGLE_H
#define FIGRECTANGLE_H

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <Utility.h>
#include <Figure.h>

class Rectangle : public Figure{
public:
	Rectangle(
		const int width,
		const int height,
		const int weight,
		const TypeDef_Color color):Figure(width, height, color){
			Weight = weight;
			drawRectangle();
	}

	void DrawFigure(std::vector<unsigned char> & image_vector) override;

	~Rectangle(){}
private:
	int Weight;

	void drawRectangle(void);
};

#endif
