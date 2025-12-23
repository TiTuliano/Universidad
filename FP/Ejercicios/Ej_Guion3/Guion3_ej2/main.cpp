#include <iostream>

using namespace std;

/*Diseñe un programa que declare un vector de 10 elementos enteros, lo rellene
completamente con valores leídos desde teclado, pida por teclado un valor X a buscar
y muestre por pantalla un mensaje de texto indicando si el valor X se encuentra o no en el vector.*/

int main()
{
    int vectorEnteros[10];
    int valorBuscar=0;
    bool encontrado=false;

    for(int i=0; i<10; i++)
        {
            cout<<"Introduce el valor "<<i+1<<" :";
            cin>>vectorEnteros[i];
        }

    cout<<"Introduce el valor a buscar en el vector: ";
    cin>>valorBuscar;

    int i=0;
    while(!encontrado && i<10)
    {
        if(valorBuscar==vectorEnteros[i])
            encontrado=true;
        else
            i++;
    }

    if(encontrado==true)
        cout<<"El valor "<<valorBuscar<<" esta en el vector."<<endl;
    else
        cout<<"El valor "<<valorBuscar<<" no esta en el vector."<<endl;


    return 0;
}
