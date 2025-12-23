#include <iostream>
#include <cstdlib>
#include <ctime>
#define TAMA 25

using namespace std;

int main()
{
    int Datos[1000];     // Vector donde se almacenan los valores a analizar
    int Valores[TAMA];   // Vector que contiene la frecuencia de aparición
    int op;
    int x = 0;           // Nº de valores almacenados en Datos

    srand(time(NULL));

    // Inicializar el array de frecuencias al principio
    for(int i=0; i<TAMA; i++)
    {
        Valores[i] = 0;
    }

    do
    {
        cout<<"\nMENU"<<endl
            <<"1. Pedir datos"<<endl
            <<"2. Analizar datos"<<endl
            <<"3. Estan todos?"<<endl
            <<"4. Valor repetido"<<endl
            <<"5. Valor repetido"<<endl
            <<"6. Mostrar datos"<<endl
            <<"7. Mostrar analisis"<<endl
            <<"8. Salir"<<endl
            <<"Elige una opcion: ";

        cin>>op;

        switch(op)
        {
            case 1:
                {
                    char opcion;
                    int valor=0;

                    cout<<"Elige si introducir los datos manualmente(m) o automaticamente(a): ";
                    cin>>opcion;

                    if(opcion=='m')
                    {
                       x = 0; // reiniciamos contador
                       while(true)
                       {
                           cout<<"Introduce un valor "<<x<<" (-1 para terminar): ";
                           cin>>valor;

                           if(valor==-1)
                               break; // salir del bucle

                           if(valor<0 || valor>24)
                           {
                               cout<<"Error: valor no permitido"<<endl;
                           }
                           else
                           {
                              Datos[x]=valor;
                              x++;
                           }
                       }
                    }
                    else if(opcion=='a')
                    {
                        cout<<"Introduce cuantos valores quieres generar: ";
                        cin>>x;

                        for (int i=0; i<x; i++)
                        {
                          Datos[i]=rand()%25; // valores entre 0 y 24
                        }
                    }
                    else
                    {
                        cout<<"Caracter no permitido"<<endl;
                    }

                    break;
                }

            case 2:
                for(int i=0; i<TAMA; i++)
                {
                    Valores[i]=0; // reiniciamos el análisis
                }

                for(int i=0; i<x; i++)
                {
                    Valores[Datos[i]]++;
                }

                for(int i=0; i<TAMA; i++)
                {
                    if(Valores[i]>0)
                    {
                        cout<<"El valor "<<i<<" se repite: "<<Valores[i]<<" veces"<<endl;
                    }
                }
                break;

            case 3:
                {
                    bool encontrado=false;

                    for(int i=0; i<TAMA && !encontrado; i++)
                    {
                        if(Valores[i]==0)
                            encontrado=true;
                    }

                    if(encontrado)
                        cout<<"Hay valores que no estan"<<endl;
                    else
                        cout<<"Estan todos los valores"<<endl;

                    break;
                }

            case 4:
                {
                    int num;
                    cout<<"Introduce el valor que quieres saber si esta repetido (0-24): ";
                    cin>>num;

                    if(num < 0 || num >= TAMA)
                    {
                        cout<<"Error: valor fuera de rango"<<endl;
                    }
                    else
                    {
                        if(Valores[num] == 0)
                            cout<<"El valor "<<num<<" no aparece en los datos"<<endl;
                        else if(Valores[num] == 1)
                            cout<<"El valor "<<num<<" aparece 1 vez (no esta repetido)"<<endl;
                        else
                            cout<<"El valor "<<num<<" esta repetido "<<Valores[num]<<" veces"<<endl;
                    }

                    break;
                }


        }

    }while(op!=8);

    return 0;
}

