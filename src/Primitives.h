#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <Figure.h>

//Point defines
#define P_SQUARE	((int)0)
#define P_ROUND		((int)1)

//Line defines
#define E_SQUARE	P_SQUARE
#define E_ROUND		P_ROUND

class Point : public Figure{
public:
	Point(const int weight, const int alpha, const int style):Figure(weight*2-1, weight*2-1){

			pWeight = weight;
			pAlpha = alpha;
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

/*
class Line : public Figure{
public:
	Line(
		const int width,
		const int height,
		const int x1,
		const int y1,
		const int x2,
		const int y2,
		const int weight,
		const int style): x1(x1), y1(y1), x2(x2), y2(y2), weight(weight), edgeStyle(style), Figure(width, height){}

	void setX1(int x1);
	void setX2(int x2);

	void setY1(int y1);
	void setY2(int y2);

	void setWeight(int weight);
	void setEdgeStyle(int edgeStyle);

	void Draw(void) override;

	~Line(){}
private:
	int x1;
	int x2;

	int y1;
	int y2;

	int weight;
	int edgeStyle;
};
*/
#endif /* FIGURE_H */
