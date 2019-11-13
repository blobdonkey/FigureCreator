#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <string>
#include <vector>
#include <Colors.h>

class Figure {
public:
	Figure(const int width, const int height, const Color color) : width(width), height(height), color(color){
		image.resize(width * height * 3);
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
	Color color;
protected:
	//Vecteur d'image
	std::vector<unsigned char> image;

	//Vide le vecteur d'image
	void ClearVector() {
		for(int counter=0; counter < image.size(); counter++) {
	    image.at(counter) = 0;
		}
	}
};

#endif /* FIGURE_H */
