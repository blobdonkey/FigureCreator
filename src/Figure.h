#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <string>
#include <vector>
#include <Colors.h>

class Figure {
public:
	Figure(const int Width, const int Height, const TypeDef_Color figure_color) : width(Width), height(Height), color(figure_color){
		image_figure.resize(width * height * 3);
		ClearVector();
	}

	~Figure(){}

	//Ecrit la figure dans un vecteur passé en paramètres
	virtual void DrawFigure(std::vector<unsigned char> & image_vector) = 0;
	//Renvoie le vecteur d'image (non modifiable)
	const std::vector<unsigned char> Get(void) const;

	//Attributs de taille
	int width;
	int height;
	TypeDef_Color color;
protected:
	//Vecteur d'image
	std::vector<unsigned char> image_figure;

	//Vide le vecteur d'image
	void ClearVector() {
		for(int counter=0; counter < image_figure.size(); counter++) {
	    image_figure.at(counter) = 0;
		}
	}
};

#endif /* FIGURE_H */
