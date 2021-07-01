#include "Ventas.h"

Ventas::Ventas()
{
    //ctor
}

Ventas::~Ventas()
{
    //dtor
}
void Ventas::setfecha(string e)
{
    fecha=e;
}

void Ventas::setcantidad(int e)
{
    cantidad=e;
}
void Ventas::setamount(int e)
{
    amount=e;
}

string Ventas::getfecha()
{
    return fecha;
}

int Ventas::getcantidad()
{
    return cantidad;
}
double Ventas::getamount()
{
    return amount;
}
void Ventas::setperiodo(int e)
{
    periodo=e;
}
int Ventas::getperiodo()
{

    return periodo;
}
