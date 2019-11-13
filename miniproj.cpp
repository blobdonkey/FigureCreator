#include <iostream>
#include <string>
#include <vector>

#include <Drawing.h>
#include <Figure.h>
#include <Primitives.h>
#include <Colors.h>

const int width = 399;
const int height = 399;

std::vector<unsigned char> image;

int main(int argc, char **argv) {

  Color color(255,0,0,255);

  Drawing sketch1(width, height);

  Figure * point1 = new Point(200,color,P_ROUND);

  //sketch1.AddFigure(point1,(width/2)-200,(height/2)-200);
  sketch1.AddFigure(point1,0,0);

  sketch1.save(std::string("test_image.bmp"));

  return 0;
}
