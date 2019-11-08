#include "Drawing.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>
#include <stdexcept>

//            _    _  _                     _    _           _
//  ___  _ _ | |_ | |<_> ___  ._ _ _  ___ _| |_ | |_  ___  _| | ___
// | . \| | || . \| || |/ | ' | ' ' |/ ._> | |  | . |/ . \/ . |<_-<
// |  _/`___||___/|_||_|\_|_. |_|_|_|\___. |_|  |_|_|\___/\___|/__/
// |_|

Drawing::Drawing(const int width, const int height) : width(width), height(height) {
  image.resize(width * height);
  createTestImage();
}

Drawing::~Drawing() {}

/* Save image to file "filename" */
void Drawing::save(std::string filename) {

  int figWidth = 0;
  int figHeight = 0;
  int figX = 0;
  int figY = 0;

  if (filename.substr(filename.find_last_of(".") + 1) != "bmp") {
    throw std::runtime_error(
        "Drawing ne supporte que l'enregistrement d'images au format bmp");
  }

  //createTestImage();

  std::vector<unsigned char> figure_image;

  for(int i = 0; i < vecteur_figures.size(); i++)
  {
    figure_image = vecteur_figures.at(i)->Get();
    figWidth = vecteur_figures.at(i)->width;
    figHeight = vecteur_figures.at(i)->height;
    figX = vecteur_coord.at(i)->x;
    figY = vecteur_coord.at(i)->y;

    //std::cout<<"figure"<<i<<" : ("<<figX<<","<<figY<<") w : "<<figWidth<<" h : "<<figHeight<<std::endl;

    for(int y = figY; y < (figHeight+figY); y++)
    {
      for(int x = figX; x < (figWidth+figX); x++)
      {
        if((y < height) && (x < width))
        {
          //std::cout<<"("<<x<<","<<y<<") <-> ("<<x-figX<<","<<y-figY<<")"<<std::endl;
          if(image.at(y * width + x) + figure_image.at((y-figY)*figWidth + (x-figX)) > 255)
          {
            image.at(y * width + x) = 255;
          }
          else
          {
            image.at(y * width + x) += figure_image.at((y-figY)*figWidth + (x-figX));
          }
        }
      }
    }
  }

  stbi_write_bmp(filename.c_str(), width, height, 1, image.data());
}

//            _             _                      _    _           _
//  ___  _ _ <_> _ _  ___ _| |_ ___  ._ _ _  ___ _| |_ | |_  ___  _| | ___
// | . \| '_>| || | |<_> | | | / ._> | ' ' |/ ._> | |  | . |/ . \/ . |<_-<
// |  _/|_|  |_||__/ <___| |_| \___. |_|_|_|\___. |_|  |_|_|\___/\___|/__/
// |_|

/* Set every point of the image to 0 */
void Drawing::clearImage() {
  for (std::vector<unsigned char>::iterator it = image.begin(); it != image.end();
       it++) {
    *it = 0;
  }
}

/* Set image to test */
void Drawing::createTestImage() {

  for (int j = 0; j < height; j++) {
    for (int i = 0; i < width; i++) {
      image[j * width + i] = (i + j) % 256;
    }
  }
}

void Drawing::AddFigure(Figure * figure, const int x_pos, const int y_pos) {

  TypeDef_Coord* coord = NULL;

  coord = (TypeDef_Coord*)malloc(sizeof(TypeDef_Coord));

  coord->x = x_pos;
  coord->y = y_pos;

  vecteur_figures.push_back(figure);
  vecteur_coord.push_back(coord);
}
