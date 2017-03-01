CPPFLAGS = -g -c -Wall -ansi

OBJETOS = main.o

All: main.x clean

main.x: $(OBJETOS)
	g++ -o main.x $(OBJETOS)

main.o: main.cpp donante.hpp donanteInterfaz.hpp funcionesMonticulo.hpp monticuloDonantes.hpp monticuloDonantesInterfaz.hpp
	g++ $(CPPFLAGS) main.cpp

clean:
	rm -f $(OBJETOS)
