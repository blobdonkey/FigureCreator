#include <iostream>
#include <unistd.h>
#include <string>
#include <vector>

#include <Drawing.h>
#include <Figure.h>
#include <Primitives.h>
#include <Colors.h>

const int width = 400;
const int height = 400;

std::vector<unsigned char> image;

int main(int argc, char **argv) {

  Drawing sketch1(width, height);

  Color color1(255,0,0,255);
  Color color2(0,255,0,255);
  Color color3(0,0,255,255);
  Color color4(255,255,255,255);

  Figure * point1 = new Point(100,color1,P_ROUND);
  Figure * point2 = new Point(100,color2,P_ROUND);
  Figure * point3 = new Point(100,color3,P_ROUND);
  Figure * point4 = new Point(100,color4,P_ROUND);

  sketch1.AddFigure(point1,0,0);
  sketch1.AddFigure(point2,width/4,0);
  sketch1.AddFigure(point3,0,height-200);
  sketch1.AddFigure(point4,width-200,height-200);

  sketch1.save(std::string("test_image.bmp"));

  /*for(int i = 0; i<255; i++){
    sketch1.clearFigures();

    color1.SetColor(255,0,0,i);
    color2.SetColor(0,255,0,i);
    color3.SetColor(0,0,255,i);
    color4.SetColor(255,255,255,i);

    Figure * point1 = new Point(100,color1,P_SQUARE);
    Figure * point2 = new Point(100,color2,P_SQUARE);
    Figure * point3 = new Point(100,color3,P_SQUARE);
    Figure * point4 = new Point(100,color4,P_SQUARE);

    sketch1.AddFigure(point1,0,0);
    sketch1.AddFigure(point2,width-200,0);
    sketch1.AddFigure(point3,0,height-200);
    sketch1.AddFigure(point4,width-200,height-200);

    sketch1.save(std::string("test_image.bmp"));

    delete point1;
    delete point2;
    delete point3;
    delete point4;
  }*/

  return 0;
}
