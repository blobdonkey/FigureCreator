STB_INCLUDE_PATH = ./extern/stb

CFLAGS = -std=c++11 -g -I$(STB_INCLUDE_PATH) -Isrc
LDFLAGS =

APP = FigureCreator
OBJ = miniproj.o Figure.o Primitives.o Drawing.o


$(APP): $(OBJ)
	g++ $(CFLAGS) -o $(APP) $(OBJ) $(LDFLAGS) -Wall
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

.PHONY: test clean

clean:
	rm -f $(APP)
	rm -f *.o
