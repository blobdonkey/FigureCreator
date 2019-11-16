#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <Utility.h>
#include <Figure.h>

//Point defines
#define P_SQUARE	((int)0)
#define P_ROUND		((int)1)

//Line defines
#define E_SQUARE	P_SQUARE
#define E_ROUND		P_ROUND

class Point : public Figure{
public:
	Point(const int weight, const TypeDef_Color color, const int style):Figure(weight*2-1, weight*2-1, color){

			pWeight = weight;
			pStyle = style;

			drawPoint();
	}

	void DrawFigure(std::vector<unsigned char> & image_vector) override;

	~Point(){}
private:
	int pWeight;
	int pAlpha;
	int pStyle;

	void drawPoint(void);
};

#endif /* FIGURE_H */
