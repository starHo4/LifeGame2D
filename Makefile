OBJS = main.o GLScene.o
CC = g++
FRAMEWORK = -framework OpenGL -framework GLUT
STD = -std=c++11

all : lifegame clean

lifegame: $(OBJS)
	$(CC) -o lifegame $(OBJS) $(FRAMEWORK) $(STD)
main.o: main.cpp
	$(CC) -c main.cpp
GLScene.o: GLScene.hpp GLScene.cpp
	$(CC) -c GLScene.cpp
clean:
	rm *.o