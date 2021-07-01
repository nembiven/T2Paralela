#include <iostream>
#include "Ventas.h"
#include "Funciones.h"
using namespace std;
int main()
{
    Ventas *A = new Ventas[384629];
    leeProcesa(A);
    Ventas B[contarfechas(A)];
   int n=contarfechas(A);
   depurar(A,B);
   perodiar(B,n);
   float b=obtenerb(B,n);
   float a=obtenera(B,b,n);
   std::cout<<"\n\nLa formula de regresi�n lineal es :\n\n "<<a<<" + "<<b<<" * n con n = periodo de dia"<<std::endl;
    return 0;
}
