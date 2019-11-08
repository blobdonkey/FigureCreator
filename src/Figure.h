
#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

class Figure {
public:
	Figure(const int width, const int height) : width(width), height(height) {
		image.resize(width * height);
		ClearVector();
	}

	~Figure(){}

	//Ecrit la figure dans un vecteur passé en paramètres
	virtual void DrawFigure(std::vector<unsigned char> & image_vector) = 0;
	//Renvoie le vecteur d'image (non modifiable)
	const std::vector<unsigned char> Get(void) const;
	//*DEBUG* Affiche la figure dans le terminal
	void printfFigure(void){

		for(int y = 0; y < height; y++)
		{
			for(int x = 0; x < width; x++)
			{
				if(image.at(y * height + x))
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
	}

	//Attributs de taille
	int width;
	int height;

protected:
	//Vecteur d'image
	std::vector<unsigned char> image;

	//Vide le vecteur d'image
	void ClearVector() {
		for(int counter=0; counter < image.size(); counter++) {
	    image.at(counter) = 0;
		}
	}

	//Frappe un pixel au coordonnées x,y. Renvoie 'true' si possible, sinon 'false'
	bool drawPixel(const int x, const int y);
	//Renvoie la valeur du pixel aux coordonnées x,y
	unsigned char getPixel(const int x, const int y);
};

#endif /* FIGURE_H */
