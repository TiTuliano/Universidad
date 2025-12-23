#include <iostream>
#include <cstring>

using namespace std;
typedef char cadena[30];

int main()
{
    cadena Tabla[3][4];
    bool encontrado=false;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            cout<<"Rellena la posicion "<<i<<" "<<j<<":";
            cin>>Tabla[i][j];
        }
    }

    cadena S;
    cout<<"Introduce la palabra a buscar: ";
    cin>>S;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(strcmp(S,Tabla[i][j])==0)
                encontrado=true;
        }
    }

    if(encontrado==true)
        cout<<"La palabra "<<S<<" esta en el vector."<<endl;
    else
        cout<<"La palabra "<<S<<" no esta en el vector."<<endl;

    return 0;
}
