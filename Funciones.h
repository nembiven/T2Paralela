#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Ventas.h"
#include <fstream>
#include <cstdlib>
#include "string.h"

void leeProcesa(Ventas []);
int dias (string,string);
int esbisiesto(int );
int contarfechas(Ventas []);
void depurar(Ventas [], Ventas []);
void perodiar(Ventas[],int);
double obtenerb(Ventas [],int );
double obtenera(Ventas [],float ,int );
#endif // FUNCIONES_H
