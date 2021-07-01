CXX=g++
CXXFLAGS= -Wall -g3
LDFLAGS= -lm

main: main.cpp Ventas.o Funciones.o 
		$(CXX) $(CXXFLAGS) -o app main.cpp Ventas.o Funciones.o  $(LDFLAGS)

Funciones.o: Funciones.h Funciones.cpp
		$(CXX) $(CXXFLAGS) -c Funciones.cpp

Estudiantes.o: Ventas.h Ventas.cpp
		$(CXX) $(CXXFLAGS) -c Ventas.cpp


	

	

.PHONY: clean
clean:
		rm -fr *.o app