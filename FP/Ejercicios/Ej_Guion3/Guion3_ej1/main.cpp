#include <iostream>

using namespace std;

/*Diseñe un programa que declare un vector de 10 elementos (enteros o reales), lo rellene completamente con
valores leídos desde teclado y calcule y muestre por pantalla el mínimo y el máximo de todos ellos.*/

int main()
{

    int vectorEnteros[10];
    int valormax;
    int valormin;

    for(int i=0; i<10; i++)
        {
            cout<<"Introduce el valor "<<i+1<<" :";
            cin>>vectorEnteros[i];
        }


    valormax=vectorEnteros[0];
    valormin=vectorEnteros[0];

    for(int i=1; i<10; i++)
        {

            if(valormax<vectorEnteros[i])
            {
                valormax=vectorEnteros[i];
            }


            if(valormin>vectorEnteros[i])
            {
                valormin=vectorEnteros[i];
            }
        }

    cout<<"El valor minimo es: "<<valormin<<endl;
    cout<<"El valor maximo es: "<<valormax<<endl;



    return 0;
}
