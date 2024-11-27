build:
	echo "Création d'un exécutable Linux"
	g++ main.cpp -o GameOfLife -lsfml-graphics -lsfml-window -lsfml-system
	echo "Terminé !\nCréation d'un exécutable Windows"
	x86_64-w64-mingw32-g++ main.cpp -o GameOfLife.exe -lsfml-graphics -lsfml-window -lsfml-system
	echo "Terminé !\nNote : La version de windows n'est pas un exécutable signé, vous aurez donc un message de protection venant de Windows"
run:
	./GameOfLife