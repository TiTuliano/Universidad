#include <iostream>

using namespace std;

int main()
{
    int Vuno[15], Vdos[15], Vfus[30];
    int numuno, numdos; /* Nº de elementos almacenados
                        en los vectores Vuno y Vdos respectivamente */

    int op;
    do
    {
        cout << "MENU " << endl;
        cout << "1. Pedir Vector 1" << endl;
        cout << "2. Pedir Vector 2" << endl;
        cout << "3. Mostrar Vectores" << endl;
        cout << "4. Mezclar Vectores" << endl;
        cout << "5. Mostrar Mezcla" << endl;
        cout << "6. Salir" << endl;
        cout << "Elija opción:";
        cin>>op;

        switch(op)
        {
        case 1:
        {
            cout<<"Cuanto numeros quieres insertar en el vector 1: ";
            cin>>numuno;

            for(int i=0; i<numuno; i++)
            {
                cout<<"Introduce el valor "<<i+1<<": ";
                cin>>Vuno[i];
            }
            break;
        }

        case 2:
        {
            cout<<"Cuanto numeros quieres insertar en el vector 2: ";
            cin>>numdos;

            for(int i=0; i<numdos; i++)
            {
                cout<<"Introduce el valor "<<i+1<<": ";
                cin>>Vdos[i];
            }
            break;
        }

        case 3:
        {
            cout<<"Vector 1:"<<endl;
            for(int i=0; i<numuno; i++)
            {
                cout<<Vuno[i]<<", ";
            }

            cout<<endl;

            cout<<"Vector 2:"<<endl;
            for(int i=0; i<numuno; i++)
            {
                cout<<Vdos[i]<<", ";
            }
            break;

        }
        case 4:
        {
            for(int i=0; i<numuno; i++)
            {
                Vfus[i]=Vuno[i];
            }

            for(int i=0; i<numdos; i++)
            {
                Vfus[i+numuno]=Vdos[i];
            }

            break;
        }
        case 5:
        {
            int numfus=numuno+numdos;

            for(int i=0; i<numfus; i++)
            {
                cout<<Vfus[i]<<", ";
            }
        }
        case 6:
            cout<<"Saliendo del programa..."<<endl;
            break;

        default:
            cout<<"Error"<<endl;
        }


    }
    while(op!=6);

    return 0;
}
