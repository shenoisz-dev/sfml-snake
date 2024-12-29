# crewate by shewnoisz
COMPILE=g++

all: main.o game.o snake.o blocks.o text.o combine clear run

main.o:
	$(COMPILE) -c src/main.cpp

game.o:
	$(COMPILE) -c src/game.cpp

snake.o:
	$(COMPILE) -c src/snake.cpp

blocks.o:
	$(COMPILE) -c src/blocks.cpp

text.o:
	$(COMPILE) -c src/text.cpp

combine:
	$(COMPILE) blocks.o snake.o game.o text.o main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

clear:
	rm -rf *.o

run:
	./sfml-app
