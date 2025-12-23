#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int main()
{
    int op;
    srand(time(NULL));
    char nombre[10][50];
    char apellidos[10][50];
    int num;

    do
    {
        cout<<endl
            <<"1.Pedir vector VNombres"<<endl
            <<"2.Pedir vector VApellidos"<<endl
            <<"3.Mostrar vectores"<<endl
            <<"4.Generar nombres de personas"<<endl
            <<"5.Salir"<<endl
            <<"Elige una opcion: ";

        cin>>op;
        cin.ignore();

        switch(op)
        {
            case 1:
                for(int i=0; i<10; i++)
                {
                    cout<<"Introduce el nombre numero "<<i+1<<" : ";
                    cin.getline(nombre[i],50);

                }
                break;

            case 2:
                for(int i=0; i<10; i++)
                {
                    cout<<"Introduce el apellido numero "<<i+1<<" : ";
                    cin.getline(apellidos[i],50);
                }
                break;

            case 3:
                for(int i=0; i<10; i++)
                {
                    cout<<nombre[i]<<","<<apellidos[i]<<endl;

                }
                break;

            case 4:
                cout<<"Introduce numero de nombres a generar: ";
                cin>>num;

                cout<<"Nombres generados: "<<endl;

                for(int i=0; i<=num; i++)
                {
                    int indiceN=rand()%10;
                    int indiceA=rand()%10;

                    cout<<nombre[indiceN]<<" "<<apellidos[indiceA]<<endl;
                }
                break;

            case 5:cout<<"Saliendo del programa..."<<endl;
                   break;

            default:cout<<"Opcion invalida"<<endl;

        }

    }while(op!=5);

    return 0;
}
