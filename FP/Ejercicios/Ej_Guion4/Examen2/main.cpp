#include <iostream>
#include <cstdlib>
#include <ctime>
#define NPlantas 3
#define NHabitaciones 10

using namespace std;

int main()
{
    int Hotel[NPlantas][NHabitaciones];
    int op;
    srand(time(0));
    do
    {
        cout<<"1.Rellenar y mostar hotel"<<endl
            <<"2.Mostrar aforo de cada planta"<<endl
            <<"3.Buscar aforo exacto"<<endl
            <<"4.Media aforo y habitaciones libres"<<endl
            <<"5.Salir"<<endl
            <<"Elige una opcion: ";
        cin>>op;

        switch(op)
        {
        case 1:
            for(int i=0; i<NPlantas; i++)
            {
                for(int j=0; j<NHabitaciones; j++)
                {
                    Hotel[i][j]=rand()%6;
                }
            }

            for(int i=0; i<NPlantas; i++)
            {
                cout<<"Planta "<<i+1<<": ";
                for(int j=0; j<NHabitaciones; j++)
                {
                    cout<<Hotel[i][j]<<" ";


                }
                cout<<endl;
            }
            break;

        case 2:
        {
            int suma=0;
            for(int i=0; i<NPlantas; i++)
            {
                suma=0;
                cout<<"Planta "<<i+1<<endl;
                for(int j=0; j<NHabitaciones; j++)
                {
                    suma=suma+Hotel[i][j];
                }
                cout<<" Suma = "<<suma<<endl;
            }
            break;
        }


        case 3:
        {
            int num=0,planta=0;
            cout<<"Introduce un numero de huespedes a buscar: ";
            cin>>num;

            cout<<"Introduce la planta a buscar: ";
            cin>>planta;

            bool encontrado=false;

            int i=0;
            while(!encontrado && i<NHabitaciones)
            {
                if(Hotel[planta-1][i]==num)
                    encontrado=true;
                else
                    i++;
            }

            if(encontrado==true)
            {
                cout<<"Se ha encontrado en la habitacion: "<<i+1<<endl;
            }
            else
                cout<<"No se ha encontrado"<<endl;
            break;
        }


        case 4:
        {
            float media=0;
            int y=0;
            for(int i=0; i<NPlantas; i++)
            {
                media=0;
                y=0;
                cout<<"Planta "<<i+1<<endl;
                for(int j=0; j<NHabitaciones; j++)
                {
                    media=media+Hotel[i][j];
                    if(Hotel[i][j]==0)
                        y++;

                }
                media=media/10;
                cout<<" Media = "<<media<<"- Habitaciones vacias= "<<y<<endl;
            }
            break;
        }


        case 5:
            cout<<"Saliendo del programa..."<<endl;
            break;

        default:
            cout<<"Opcion invalida"<<endl;
        }

    }
    while(op!=5);
    return 0;
}
