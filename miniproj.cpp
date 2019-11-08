#include <iostream>
#include <string>

#include <Drawing.h>

const int width = 1000;
const int height = 1000;

std::vector<unsigned char> image;

int main(int argc, char **argv) {

  Drawing sketch1(width, height);

  Figure * point1 = new Point(200,128,P_ROUND);
  Figure * point2 = new Point(20,255,P_ROUND);
  Figure * point3 = new Point(30,255,P_ROUND);
  Figure * point4 = new Point(40,255,P_ROUND);

  /*
  point1->DrawFigure(image);

  for(int y = 0; y < 19; y++)
  {
    for(int x = 0; x < 19; x++)
    {
      if(image.at(y * 19 + x))
      {
        std::cout<<"■ ";
      }
      else
      {
        std::cout<<"  ";
      }
    }
    std::cout<<std::endl;
  }
*/

  sketch1.AddFigure(point1,width/2,height/2);

  /*
  for(int i = 0; i < sketch1.vecteur_figures.size(); i++)
  {
    std::cout<<"figure"<<i<<".coordonnées : ("<<sketch1.vecteur_coord.at(i)->x<<","<<sketch1.vecteur_coord.at(i)->y<<")"<<std::endl;
    sketch1.vecteur_figures.at(i)->printfFigure();
    std::cout<<std::endl<<std::endl;
  }
  */

  sketch1.save(std::string("test_image.bmp"));

  return 0;
}
