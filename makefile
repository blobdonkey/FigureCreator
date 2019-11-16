STB_INCLUDE_PATH = ./extern/stb

CFLAGS = -std=c++11 -g -I$(STB_INCLUDE_PATH) -Isrc
LDFLAGS =

APP = FigureCreator
OBJ = miniproj.o Utility.o Colors.o Figure.o Primitives.o FigCross.o FigRectangle.o FigSegment.o Drawing.o Menu.o

$(APP): $(OBJ)
	g++ $(CFLAGS) -o $(APP) $(OBJ) $(LDFLAGS)
	rm *.o

miniproj.o: miniproj.cpp
	g++ $(CFLAGS) -c miniproj.cpp $(LDFLAGS)

Drawing.o: src/Drawing.cpp
	g++ $(CFLAGS) -c src/Drawing.cpp $(LDFLAGS)

#Inclusion de Figure
Figure.o: src/Figure.cpp
	g++ $(CFLAGS) -c src/Figure.cpp $(LDFLAGS)

#Inclusion de Figure
Primitives.o: src/Primitives.cpp
	g++ $(CFLAGS) -c src/Primitives.cpp $(LDFLAGS)

#Inclusion de Figure
FigCross.o: src/FigCross.cpp
	g++ $(CFLAGS) -c src/FigCross.cpp $(LDFLAGS)

#Inclusion de Figure
FigRectangle.o: src/FigRectangle.cpp
	g++ $(CFLAGS) -c src/FigRectangle.cpp $(LDFLAGS)

FigSegment.o: src/FigSegment.cpp
	g++ $(CFLAGS) -c src/FigSegment.cpp $(LDFLAGS)

Colors.o: src/Colors.cpp
	g++ $(CFLAGS) -c src/Colors.cpp $(LDFLAGS)

Utility.o: src/Utility.cpp
	g++ $(CFLAGS) -c src/Utility.cpp $(LDFLAGS)

Menu.o: src/Menu.cpp
	g++ $(CFLAGS) -c src/Menu.cpp $(LDFLAGS)

.PHONY: test clean

clean:
	rm -f $(APP)
	rm -f *.o
