#include <Menu.h>

void Menu::PrintMenu(void){

	system("clear");

	std::cout<<"  ______ _                         _____                _             "<<std::endl;
	std::cout<<" |  ____(_)                       / ____|              | |            "<<std::endl;
	std::cout<<" | |__   _  __ _ _   _ _ __ ___  | |     _ __ ___  __ _| |_ ___  _ __ "<<std::endl;
	std::cout<<" |  __| | |/ _` | | | | '__/ _ \\ | |    | '__/ _ \\/ _` | __/ _ \\| '__|"<<std::endl;
	std::cout<<" | |    | | (_| | |_| | | |  __/ | |____| | |  __/ (_| | || (_) | |   "<<std::endl;
	std::cout<<" |_|    |_|\\__, |\\__,_|_|  \\___|  \\_____|_|  \\___|\\__,_|\\__\\___/|_|   "<<std::endl;
	std::cout<<"            __/ |                                                     "<<std::endl;
	std::cout<<"           |___/                                                      "<<std::endl;

	std::cout<<std::endl;
	std::cout
	<<"1- Ajoutez une forme"<<std::endl
	<<"2- Enregistrer l'image"<<std::endl
	<<"3- Quitter le programme"<<std::endl
	<<std::endl
	<<"Choix : ";
}

void Menu::Run(void){

	Figure * figure = NULL;
	int X,Y = 0;
	char buffer[10];
	int choix = 0;
	Drawing sketch(width, height);

	while(1)
	{
		do{
			PrintMenu();
			std::cin>>buffer;
			choix = atoi(buffer);
		}while((choix<=0)||(choix>EXIT_MENU));

		switch(choix)
		{
			case NEW_FIG:
				figure = InsertFigure();//Récupère le pointeur de la figure entrée par l'utilisateur

				do{
					std::cout<<"Position X : ";
					std::cin>>buffer;
					X = atoi(buffer);
				}while((X<0)||(X>width));

				do{
					std::cout<<"Position Y : ";
					std::cin>>buffer;
					Y = atoi(buffer);
				}while((Y<0)||(Y>height));

				sketch.AddFigure(figure,X,Y);//Ajoute au drawing la figure entrée par l'utilisateur

			break;

			case SAVE_SKETCH:
				sketch.save(std::string("test_image.bmp"));//Sauvegarde le drawing en image
			break;

			case EXIT_MENU:
				system("clear");
				exit(0);//Quitte le programme
			break;

			default:
			break;
		}
	}
}

Figure * Menu::InsertFigure(void){

	Figure * figure = NULL;

	char buffer[10];
	int choix = 0;

	do{
		system("clear");

		std::cout
		<<"1- Ajouter un Point"<<std::endl
		<<"2- Ajouter une Croix"<<std::endl
		<<"3- Ajouter un Rectangle"<<std::endl
		<<"4- Ajouter un Carré"<<std::endl
		<<"5- Ajouter un Segment"<<std::endl
		<<std::endl
		<<"Choix : ";

		std::cin>>buffer;
		choix = atoi(buffer);
	}while((choix<=0)||(choix>FIG_SEGMENT));

	switch(choix)
	{
		case FIG_POINT:
			figure = AddPoint();
			return figure;//Renvoie un pointeur de figure de type point
		break;

		case FIG_CROSS:
			figure = AddCross();
			return figure;//Renvoie un pointeur de figure de type croix
		break;

		case FIG_RECTANGLE:
			figure = AddRectangle();
			return figure;//Renvoie un pointeur de figure de type rectangle
		break;

		case FIG_SQUARE:
			figure = AddSquare();
			return figure;//Renvoie un pointeur de figure de type carré
		break;

		case FIG_SEGMENT:
			figure = AddSegment();
			return figure;//Renvoie un pointeur de figure de type segment
		break;
	}
}

Figure * Menu::AddPoint(void){

	char buffer[10];
	int Size = 0;
	unsigned char Alpha = 0;
	TypeDef_Color color;

	system("clear");

	std::cout<<"Ajout de Point"<<std::endl;
	do{
		std::cout<<"Taille : ";
		std::cin>>buffer;
		Size = atoi(buffer);
	}while(Size<=0);

	do{
		std::cout<<"Couleur (R) : ";
		std::cin>>buffer;
		color.r = atoi(buffer);
	}while(color.r<0);

	do{
		std::cout<<"Couleur (G) : ";
		std::cin>>buffer;
		color.g = atoi(buffer);
	}while(color.g<0);

	do{
		std::cout<<"Couleur (B) : ";
		std::cin>>buffer;
		color.b = atoi(buffer);
	}while(color.b<0);

	do{
		std::cout<<"Couleur (Alpha) : ";
		std::cin>>buffer;
		Alpha = atoi(buffer);
	}while(Alpha<0);

	color.r = color.r*((float)Alpha/255);
	color.g = color.g*((float)Alpha/255);
	color.b = color.b*((float)Alpha/255);

	Figure * point = new Point(Size,color,P_ROUND);

	return point;
}

Figure * Menu::AddCross(void){

	char buffer[10];
	int Size = 0;
	int Weight = 0;
	unsigned char Alpha = 0;
	TypeDef_Color color;

	system("clear");

	std::cout<<"Ajout de Croix"<<std::endl;
	do{
		std::cout<<"Taille : ";
		std::cin>>buffer;
		Size = atoi(buffer);
	}while(Size<=0);

	do{
		std::cout<<"Largeur de trait : ";
		std::cin>>buffer;
		Weight = atoi(buffer);
	}while(Weight<=0);

	do{
		std::cout<<"Couleur (R) : ";
		std::cin>>buffer;
		color.r = atoi(buffer);
	}while(color.r<0);

	do{
		std::cout<<"Couleur (G) : ";
		std::cin>>buffer;
		color.g = atoi(buffer);
	}while(color.g<0);

	do{
		std::cout<<"Couleur (B) : ";
		std::cin>>buffer;
		color.b = atoi(buffer);
	}while(color.b<0);

	do{
		std::cout<<"Couleur (Alpha) : ";
		std::cin>>buffer;
		Alpha = atoi(buffer);
	}while(Alpha<0);

	color.r = color.r*((float)Alpha/255);
	color.g = color.g*((float)Alpha/255);
	color.b = color.b*((float)Alpha/255);

	Figure * croix = new Cross(Size,Weight,color);

	return croix;
}

Figure * Menu::AddRectangle(void){

	char buffer[10];
	int Width,Height = 0;
	int Weight = 0;
	unsigned char Alpha = 0;
	TypeDef_Color color;

	system("clear");

	std::cout<<"Ajout de Rectangle"<<std::endl;

	do{
		std::cout<<"Longeur : ";
		std::cin>>buffer;
		Width = atoi(buffer);
	}while(Width<=0);

	do{
		std::cout<<"Hauteur : ";
		std::cin>>buffer;
		Height = atoi(buffer);
	}while(Height<=0);

	do{
		std::cout<<"Largeur de trait : ";
		std::cin>>buffer;
		Weight = atoi(buffer);
	}while(Weight<=0);

	do{
		std::cout<<"Couleur (R) : ";
		std::cin>>buffer;
		color.r = atoi(buffer);
	}while(color.r<0);

	do{
		std::cout<<"Couleur (G) : ";
		std::cin>>buffer;
		color.g = atoi(buffer);
	}while(color.g<0);

	do{
		std::cout<<"Couleur (B) : ";
		std::cin>>buffer;
		color.b = atoi(buffer);
	}while(color.b<0);

	do{
		std::cout<<"Couleur (Alpha) : ";
		std::cin>>buffer;
		Alpha = atoi(buffer);
	}while(Alpha<0);

	color.r = color.r*((float)Alpha/255);
	color.g = color.g*((float)Alpha/255);
	color.b = color.b*((float)Alpha/255);

	Figure * rectangle = new Rectangle(Width,Height,Weight,color);

	return rectangle;
}

Figure * Menu::AddSquare(void){

	char buffer[10];
	int Width = 0;
	int Weight = 0;
	unsigned char Alpha = 0;
	TypeDef_Color color;

	system("clear");

	std::cout<<"Ajout de Rectangle"<<std::endl;

	do{
		std::cout<<"Taille : ";
		std::cin>>buffer;
		Width = atoi(buffer);
	}while(Width<=0);

	do{
		std::cout<<"Largeur de trait : ";
		std::cin>>buffer;
		Weight = atoi(buffer);
	}while(Weight<=0);

	do{
		std::cout<<"Couleur (R) : ";
		std::cin>>buffer;
		color.r = atoi(buffer);
	}while(color.r<0);

	do{
		std::cout<<"Couleur (G) : ";
		std::cin>>buffer;
		color.g = atoi(buffer);
	}while(color.g<0);

	do{
		std::cout<<"Couleur (B) : ";
		std::cin>>buffer;
		color.b = atoi(buffer);
	}while(color.b<0);

	do{
		std::cout<<"Couleur (Alpha) : ";
		std::cin>>buffer;
		Alpha = atoi(buffer);
	}while(Alpha<0);

	color.r = color.r*((float)Alpha/255);
	color.g = color.g*((float)Alpha/255);
	color.b = color.b*((float)Alpha/255);

	Figure * carre = new Rectangle(Width,Width,Weight,color);

	return carre;
}

Figure * Menu::AddSegment(void){

	char buffer[10];
	int X,Y = 0;
	int Weight = 0;
	unsigned char Alpha = 0;
	TypeDef_Color color;

	system("clear");

	std::cout<<"Ajout de Segment"<<std::endl;

	do{
		std::cout<<"X : ";
		std::cin>>buffer;
		X = atoi(buffer);
	}while(X<0);

	do{
		std::cout<<"Y : ";
		std::cin>>buffer;
		Y = atoi(buffer);
	}while(Y<0);

	do{
		std::cout<<"Couleur (R) : ";
		std::cin>>buffer;
		color.r = atoi(buffer);
	}while(color.r<0);

	do{
		std::cout<<"Couleur (G) : ";
		std::cin>>buffer;
		color.g = atoi(buffer);
	}while(color.g<0);

	do{
		std::cout<<"Couleur (B) : ";
		std::cin>>buffer;
		color.b = atoi(buffer);
	}while(color.b<0);

	do{
		std::cout<<"Couleur (Alpha) : ";
		std::cin>>buffer;
		Alpha = atoi(buffer);
	}while(Alpha<0);

	color.r = color.r*((float)Alpha/255);
	color.g = color.g*((float)Alpha/255);
	color.b = color.b*((float)Alpha/255);

	Figure * segment = new Segment(X,Y,color);

	return segment;
}
