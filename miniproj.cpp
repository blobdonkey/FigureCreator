#include <iostream>
#include <unistd.h>
#include <string>
#include <vector>

#include <Drawing.h>
#include <Figure.h>
#include <Primitives.h>
#include <FigCross.h>
#include <FigRectangle.h>
#include <Colors.h>
#include <Menu.h>

int width = 0;
int height = 0;

int main(int argc, char **argv) {

  //std::cout<<"argc à "<<argc<<std::endl;

  if(argc == 3)
  {
    width = atoi(argv[1]);
    height = atoi(argv[2]);

    std::cout<<"Menu("<<width<<","<<height<<")"<<std::endl;
  }

  Menu * menu = new Menu(width,height);

  menu->Run();

  /*
  Color color1(0,255,0,255);

  Figure * cross = new Cross(100,1,color1);
  Figure * rectangle = new Rectangle(60,80,1,color1);

  sketch1.AddFigure(cross,0,0);
  sketch1.AddFigure(rectangle,0,0);

  sketch1.save(std::string("test_image.bmp"));
  */

  return 0;
}
