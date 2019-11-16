
#ifndef FIGSEGMENT_H
#define FIGSEGMENT_H

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <Utility.h>
#include <Figure.h>

class Segment : public Figure{
public:
	Segment(
		const int x,
		const int y,
		const TypeDef_Color color):Figure(x+1, y+1, color){
			drawSegment();
	}

	void DrawFigure(std::vector<unsigned char> & image_vector) override;

	~Segment(){}
private:
	void drawSegment(void);
};

#endif
