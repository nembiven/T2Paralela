#ifndef VENTAS_H
#define VENTAS_H
#include<stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

class Ventas
{
    public:
        Ventas();
        virtual ~Ventas();
        void setfecha(string e);
        void setsku(int e);
        void setcantidad(int e);
        void setamount(int e);
        void setnombre(string e);
        void setperiodo(int e);
        int getperiodo();
        string getfecha();
        int getcantidad();
        double getamount();

    private:
        string fecha;
        long int periodo;
        int cantidad;
        double amount;

};

#endif // VENTAS_H
