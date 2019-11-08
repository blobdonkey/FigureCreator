#ifndef FIGCROSS_H
#define FIGCROSS_H

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <Figure.h>
#include <Primitives.h>

class FigCross : public Figure{
public:
	FigCross(const int x, const int y, const int height): x(x), y(y), height(height)
	{
		Figure(height, height);
	}

	void Draw(void) override;

	~FigCross(){}
private:
	int x;
	int y;

	int height;
};

#endif /* FIGURE_H */
