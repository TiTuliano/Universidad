#include <iostream>
#include <cstdlib>
#include <ctime>
#define NTiendas 4
#define NDias 7

using namespace std;

int main()
{
    float Tiendas[NTiendas][NDias];
    int op;
    float media=0;
    srand(time(0));

    do
    {
        cout<<endl
            <<"1.Rellenar tiendas"<<endl
            <<"2.Mostrar medias semanales"<<endl
            <<"3.Buscar ganancia exacta"<<endl
            <<"4.Reiniciar tienda"<<endl
            <<"5.Salir"<<endl
            <<"Elige una opcion: ";

        cin>>op;

        switch(op)
        {
        case 1:
            for(int i=0; i<NTiendas; i++)
            {
                for(int j=0; j<NDias; j++)
                {
                    Tiendas[i][j]=rand()%101;
                }
            }
            for(int i=0; i<NTiendas; i++)
            {
                cout<<"Tienda "<<i+1<<endl;
                for(int j=0; j<NDias; j++)
                {
                    cout<<Tiendas[i][j]<<" ";
                    if(j==6)
                        cout<<endl;
                }
            }
            break;

        case 2:
            for(int i=0; i<NTiendas; i++)
            {
                cout<<"Tienda "<<i+1<<endl;
                for(int j=0; j<NDias; j++)
                {
                    media=0;
                    media=Tiendas[i][j];
                    media=media/7;
                    cout<<"X"<<j<<"Ganancias: "<<media<<endl;

                }
            }
            break;

        case 3:
        {
            float cantidad;
            cout<<"Cantidad a buscar (entre 0 y 100): ";
            cin>>cantidad;

            bool encontrado=false;
            int x=0,y=0;

            while(!encontrado && x<NTiendas)
            {
                if(Tiendas[x][y]==cantidad)
                    encontrado=true;
                else
                {
                    if(y==6)
                    {
                        x++;
                        y=0;
                    }
                    else y++;
                }

            }
            if(encontrado==true)
                cout<<"La cantidad pertenece a la tienda: "<<x+1<<endl;
            else
                cout<<"Cantidad no encontrada"<<endl;
            break;

        }

        case 4:
        {
            int t=0;
            cout<<"Introduce la tienda que quieres reiniciar(del 1 al 4): ";
            cin>>t;

            t=t-1;
            for(int j=0; j<NDias; j++)
            {
                Tiendas[t][j]=0;
            }
            for(int i=0; i<NTiendas; i++)
            {
                cout<<"Tienda "<<i+1<<endl;
                for(int j=0; j<NDias; j++)
                {
                    cout<<Tiendas[i][j]<<" ";
                    if(j==6)
                        cout<<endl;
                }
            }
            break;
        }

        case 5:
            cout<<"Saliendo del programa..."<<endl;
            break;

        default:
            cout<<"Opcion incorrecta"<<endl;

        }


    }
    while(op!=5);
    return 0;
}
