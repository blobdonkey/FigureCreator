#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <vector>

#include <Drawing.h>
#include <Colors.h>
#include <Primitives.h>
#include <FigRectangle.h>
#include <FigCross.h>
#include <FigSegment.h>

//Menu options
#define NEW_FIG			((int)1)
#define SAVE_SKETCH	((int)2)
#define EXIT_MENU		((int)3)

//Figures options
#define FIG_POINT			((int)1)
#define FIG_CROSS			((int)2)
#define FIG_RECTANGLE	((int)3)
#define FIG_SQUARE		((int)4)
#define FIG_SEGMENT		((int)5)

class Menu{
public:
	Menu(const int Width, const int Height):width(Width),height(Height){

		char buffer[30];

		if((width==0)||(height==0))
		{
			do{
				std::cout<<"Entrez la longeur de l'image : ";
				std::cin>>buffer;
				width = atoi(buffer);
			}while(width<=0);

			do{
				std::cout<<"Entrez la largeur de l'image : ";
				std::cin>>buffer;
				height = atoi(buffer);
			}while(height<=0);
		}
	}
	~Menu(){}

	void Run();

protected:
	std::vector<unsigned char> image;

	int width;
	int height;

	void PrintMenu(void);
	Figure * InsertFigure(void);
	Figure * AddPoint(void);
	Figure * AddCross(void);
	Figure * AddRectangle(void);
	Figure * AddSquare(void);
	Figure * AddSegment(void);
};

#endif
