#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int tablaEnteros[10][15];
    int valorBuscar=0;
    bool encontrado=false;
    srand(time(0));

    for(int i=0; i<10; i++)
    {
        for(int j=0; j<15; j++)
        {
            tablaEnteros[i][j]=rand() %100;
        }
    }

    cout<<"Introduce el valor a buscar en el vector: ";
    cin>>valorBuscar;

    for(int i=0; i<10; i++)
    {
        for(int j=0; j<15; j++)
        {
            if(valorBuscar==tablaEnteros[i][j])
                encontrado=true;
        }
    }

    if(encontrado==true)
        cout<<"El valor "<<valorBuscar<<" esta en el vector."<<endl;
    else
        cout<<"El valor "<<valorBuscar<<" no esta en el vector."<<endl;

    return 0;
}
