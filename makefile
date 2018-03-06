all:
	g++ -I ./lib -c Vector.cpp
	g++ -o Vector Vector.o
	rm -f *.o
	./Vector
