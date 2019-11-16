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

  if(argc == 3)
  {
    width = atoi(argv[1]);
    height = atoi(argv[2]);

    std::cout<<"Menu("<<width<<","<<height<<")"<<std::endl;
  }

  Menu * menu = new Menu(width,height);

  menu->Run();//Lance le Menu

  return 0;
}
