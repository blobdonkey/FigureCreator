#include <Drawing.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>
#include <stdexcept>
#include <unistd.h>

#include <Colors.h>

//            _    _  _                     _    _           _
//  ___  _ _ | |_ | |<_> ___  ._ _ _  ___ _| |_ | |_  ___  _| | ___
// | . \| | || . \| || |/ | ' | ' ' |/ ._> | |  | . |/ . \/ . |<_-<
// |  _/`___||___/|_||_|\_|_. |_|_|_|\___. |_|  |_|_|\___/\___|/__/
// |_|

Drawing::Drawing(const int Width, const int Height) : width(Width), height(Height) {
  image.resize(width * height * 3);
  clearImage();
  //createTestImage();
}

Drawing::~Drawing() {}

/* Save image to file "filename" */
void Drawing::save(std::string filename) {

  std::vector<unsigned char> figure_image;
  int figWidth,figHeight = 0;
  int figX,figY = 0;
  TypeDef_Color figure_color;

  if (filename.substr(filename.find_last_of(".") + 1) != "bmp") {
    throw std::runtime_error(
        "Drawing ne supporte que l'enregistrement d'images au format bmp");
  }

  for(int i = 0; i < vecteur_figures.size(); i++)
  {
    figure_image = vecteur_figures.at(i)->Get();
    figWidth = vecteur_figures.at(i)->width;
    figHeight = vecteur_figures.at(i)->height;
    figX = vecteur_coord.at(i)->x;
    figY = vecteur_coord.at(i)->y;

    for(int y = 0; y < figHeight; y++)
    {
      for(int x = 0; x < figWidth; x++)
      {
        getPixel(figWidth,figHeight,x,y,figure_color,figure_image);
        drawPixel(width,height,x+figX,y+figY,figure_color,image);
      }
    }
  }
  stbi_write_bmp(filename.c_str(), width, height, 3, image.data());
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

void Drawing::clearFigures(void)
{
  vecteur_figures.clear();
  vecteur_coord.clear();
}
