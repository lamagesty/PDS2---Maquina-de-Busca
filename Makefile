tp_executavel: main.o indice_invertido.o
	c++ main.o indice_invertido.o -I include -o tp_executavel

indice_invertido.o: indice_invertido.cpp
	c++ -c indice_invertido.cpp -I include -o indice_invertido.o

build/main.o: main.cpp indice_invertido.cpp
	c++ -c main.cpp  -I include -o main.o