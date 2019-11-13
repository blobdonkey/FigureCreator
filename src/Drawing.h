#ifndef DRAWING_H
#define DRAWING_H

#include <string>
#include <vector>

//User Functions
#include <Utility.h>
#include <Figure.h>
#include <Colors.h>

typedef struct{
  int x;
  int y;
} TypeDef_Coord;

class Drawing {
public:
  Drawing(const int width, const int height);
  ~Drawing();

  void save(std::string filename);
  void AddFigure(Figure * figure, const int x_pos, const int y_pos);

  std::vector<Figure*>vecteur_figures;
  std::vector<TypeDef_Coord*>vecteur_coord;

private:
  void clearImage();
  void createTestImage();

  const int width;
  const int height;

  std::vector<unsigned char> image;
};

#endif /* DRAWIN_H */
