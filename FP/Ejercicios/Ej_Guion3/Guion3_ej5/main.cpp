#include <iostream>
#include <cstring>

using namespace std;
typedef char cadena[30];

struct persona
{
    int dni;
    cadena nombre;
};

int main()
{
    bool encontrado=false;
    persona Tabla[2][4];
    for(int i=0; i<2; i++)
        {
            for(int j=0; j<4; j++)
            {
                cout<<"Introduce el nombre: ";
                cin>>Tabla[i][j].nombre;
                cout<<"Introduce dni: ";
                cin>>Tabla[i][j].dni;
            }
        }

     int dni;
     cout<<"Introduce un dni a buscar: ";
     cin>>dni;

      for(int i=0; i<2; i++)
        {
            for(int j=0; j<4; j++)
            {
                if(Tabla[i][j].dni==dni)
                {
                  encontrado=true;
                    cout<<"El dni: "<<dni<<" pertenece a: "<<Tabla[i][j].nombre<<endl;
                }

            }
        }

    if(encontrado==false)
        cout<<"El dni: "<<dni<<" no esta en la base de datos"<<endl;

    return 0;
}
