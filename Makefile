build:
	g++ -g *.cpp -o GameOfLife -lsfml-graphics -lsfml-window -lsfml-system
windows:
	x86_64-w64-mingw32-g++ -g *.cpp -o GameOfLife -lsfml-graphics -lsfml-window -lsfml-system
run:
	./GameOfLife