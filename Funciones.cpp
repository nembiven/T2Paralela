#include "Funciones.h"

void leeProcesa(Ventas A[])
{

    string lineadatos;
    int i=0;
    ifstream datos;
	datos.open("datos.csv", ios::in); //Abrimos en el archivo datos el estudiantes.csv

	if (datos.fail()) { //En caso de no encontrarse el archvo coutear que no se puede acceder
		std::cout << "No se pudo acceder al archivo ";
		exit(1);
	}
	int ini, fin;
	string leer;//string para almacenar los datos leidos en el archivo
	char delimitador=';';
    getline(datos,lineadatos);
	while (getline(datos, lineadatos)){ //Iteraci�n para leer todo el csv

	///  1) fecha
		ini = 0;								//| Variable auxiliar para definir inicio de string
		fin = lineadatos.find(delimitador);		//| Variable para encontrar el ; y encontrar el final
		leer = lineadatos.substr(ini, fin);		//| Restar el ultimo ; para dejar el string libre
        leer.erase(leer.begin());				//| Borrar la primera "
		leer.pop_back();
		leer = leer.substr(0,10);						//|	Borrar la segunda "
		A[i].setfecha(leer.c_str());



    ///  2) sku
        lineadatos = lineadatos.substr(fin + 1);
		ini = 0;
		fin = lineadatos.find(delimitador);
		leer = lineadatos.substr(ini, fin);
		leer.erase(leer.begin());
		leer.pop_back();



    ///  3) cantidad
        lineadatos = lineadatos.substr(fin + 1);
		ini = 0;
		fin = lineadatos.find(delimitador);
		leer =  lineadatos.substr(ini, fin);
		leer.erase(leer.begin());
		leer.pop_back();
        A[i].setcantidad(atoi(leer.c_str()));



    ///  4) amount
        lineadatos = lineadatos.substr(fin + 1);
		ini = 0;
		fin = lineadatos.find(delimitador);
		leer = lineadatos.substr(ini, fin);
		leer.erase(leer.begin());
		leer.pop_back();
		A[i].setamount(atoi(leer.c_str()));




		i++;//iterador para mover el array
	}


	datos.close();//cierre del archivo
}
int esbisiesto(int anio) {
  if (anio%100==0 && anio%400!=0) return 0;
  if (anio%4==0 || anio%400==0) return 1;
  else return 0;
}

int dias (string fecha1, string fecha2)
{
    int an1=0,an2=0,me1=0,me2=0,di1=0,di2=0;

    an1+=atoi(fecha1.substr(0,4).c_str());
    an2+=atoi(fecha2.substr(0,4).c_str());

    me1+=atoi(fecha1.substr(5,2).c_str());
    me2+=atoi(fecha2.substr(5,2).c_str());

    di1+=atoi(fecha1.substr(8,2).c_str());
    di2+=atoi(fecha2.substr(8,2).c_str());




 int difan, difdi=0, i, regBisan1 = 0, regBisan2;
 int tot_dias[] = { 00,31,28,31,30,31,30,31,31,30,31,30,31 };

  difan = an2 - an1;
  regBisan1 = esbisiesto(an1);
  if( difan == 0)
  {
        if( me1 == me2)
        {
         difdi += di2 - di1;
        }
        else
        {
         difdi += (tot_dias[me1] - di1);
            if( me1 == 2 )
            {
                difdi += regBisan1;

            }
            for( i=me1+1; i < me2; i++)
            {
                if( i == 2 )
                {
                    difdi += regBisan1;
                }
                difdi += tot_dias[i];
            }
            difdi += di2;
        }
    }
      else
      {
        difdi += (tot_dias[me1] - di1);

        if(me1 == 2)
        {
            difdi += regBisan1;
        }
        if( me1 < 12 )
        {
            for( i = me1 +1; i <= 12; i++ )
            {
                difdi += tot_dias[i];
            }
        }
        difdi+=regBisan1;
        for( i=an1 +1; i < an2; i++)
        {
            difdi += 365;
            regBisan1 = esbisiesto(i);
            difdi += regBisan1;
        }
        regBisan2 = esbisiesto(an2);
        for( i=1; i < me2; i++ )
        {
            if( i == 2 ){
                difdi += regBisan2;
            }
            difdi += tot_dias[i];

        }
        difdi += di2;

    }

    return difdi;
}
int contarfechas(Ventas A[])
{
    string aux="uwu";
    int cont=0;
    for(int i=0;i<384629;i++)
    {
        if(A[i].getfecha()!=aux)
        {
            aux=A[i].getfecha();
            cont++;
        }
    }
    return cont;
}

void depurar(Ventas A[], Ventas B[])
{
    string aux=A[0].getfecha();
    B[0].setfecha(aux);
    int cont=0,acumulado=0;
    for(int i=0;i<384630;i++)
    {
        if(A[i].getfecha()!=B[cont].getfecha() && A[i].getfecha()!="")
        {
            B[cont].setamount(acumulado);
            cont++;
            B[cont].setfecha(A[i].getfecha());
            acumulado=0;
            acumulado+=(A[i].getcantidad()*A[i].getamount());

        }
        else
        {
            acumulado+=(A[i].getcantidad()*A[i].getamount());
        }

    }
    B[cont].setamount(acumulado);
}
void perodiar(Ventas A[],int n)
{
    for(int i=0;i<n;i++)
    {
        A[i].setperiodo(1+dias(A[0].getfecha(),A[i].getfecha()));
    }
}
double obtenerb(Ventas A[],int n)
{
    double y=0,x=0,xcuad=0,xy=0;
    for(int i=0;i<n;i++)
    {
        xy+=(A[i].getperiodo()*A[i].getamount());
        x+=A[i].getperiodo(); //bien
        y+=A[i].getamount(); //bien
        xcuad+=(A[i].getperiodo()*A[i].getperiodo());
    }
    std::cout<<"Los datos fueron analizados de forma que se acumularon todas las ventas por dia\nA demas se le dieron periodo a las fechas contando como el 14/10/2020 como fecha 1\n y 17/06/2021 como fecha 248 (debido a la diferencia de dias entre ambas fechas)"<<std::endl;
    std::cout<<"--------------------\n";
    std::cout<<" X = Periodo de fechas enumeradas tomando el 14/10/2020 como fecha 1,\n\t\t\t\t\t     15/10/2020 como fecha 2,\n\t\t\t\t\t     16/10/2020 como fecha 3 etc...\n";
    std::cout<<" Y = Monto acumulado de las ventas por dia";
    std::cout<<"\n--------------------\n";
    std::cout<<"Aplicando la formula de regresi�n lineal = A+B*n con n como numero de dia\n\n\n";
    std::cout<<"Tenemos que B = N(Sum(x*y)) - Sum(x)*(Sum(y)\n";
    std::cout<<"                ----------------------------\n";
    std::cout<<"                 N(Sum(x*x))-(Sum(x)*Sum(x))\n\n\n";
    std::cout<<"            A = Sum(y) - B*Sum(x)\n";
    std::cout<<"                -----------------"<<std::endl;
    std::cout<<"                       N\n"<<std::endl;
    std::cout<<" Cantidad de dias estudiados "<<n<<std::endl<<" Sumatoria de X = "<<x<<std::endl<<" Sumatoria de Y = "<<y<<std::endl<<" Sumatoria de XY = "<<xy<<std::endl<<" Sumatoria de  X al cuadrado = "<<xcuad<<std::endl;
    double arriba=(n*xy)-(x*y);
    double abajo=(n*xcuad)-(x*x);
    return arriba/abajo;

}
double obtenera(Ventas A[],float b,int n)
{
    double y=0,x=0;
    for(int i=0;i<n;i++)
    {
        y+=A[i].getamount();
        x+=A[i].getperiodo();
    }
    double arriba=y-(b*x);
    return arriba/n;
}
