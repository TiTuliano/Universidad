#include <iostream>
using namespace std;

class Vector
{
    float valores[15];
    int nElem; //numero de elementos del atributo valores

    public:
        Vector();
        bool rellenar(int cuantos);
        void mostrar();
        int getnElem();
        float getValor(int pos);
        int menorRelativo(int P);
        void intercambio(int pos1,int pos2);
};

Vector::Vector()
{
    nElem=0;
}

bool Vector::rellenar(int cuantos)
{
    int valor;
    bool insertado=false;

    if(cuantos>=1 && cuantos<=15)
    {
        for(int i=0; i<cuantos; i++)
        {
            cout<<"Introduce un valor a insertar: ";
            cin>>valor;
            valores[i]=valor;
            nElem++;
        }

        insertado=true;
    }

   return insertado;
}

void Vector::mostrar()
{
    for(int i=0; i<nElem; i++)
    {
        cout<<valores[i]<<" ";
    }
}

int Vector::getnElem()
{
    return nElem;
}

float Vector::getValor(int pos)
{
    return valores[pos];
}

int Vector::menorRelativo(int P)
{
   int menor=valores[P];

   for(int i=P; i<nElem; i++)
   {
       if(menor>valores[i])
       {
           menor=valores[i];
       }
   }

   return menor;
}

void Vector::intercambio(int pos1,int pos2)
{
    int intercambio1,intercambio2;

    intercambio1=valores[pos1];
    intercambio2=valores[pos2];

    valores[pos1]=intercambio2;
    valores[pos2]=intercambio1;

}


int main()
{
   Vector v;
   int op;

   do
   {
        cout<<"---MENU---"<<endl
            <<"1.Rellenar vector"<<endl
            <<"2. Mostrar vector"<<endl
            <<"3. Menor relativo"<<endl
            <<"4. Ordenar vector de menor a mayor"<<endl
            <<"5. Salir"<<endl
            <<"Elige Opcion: ";
        cin>>op;

        switch(op)
        {
            case 1:
                int nValores;

                cout<<"Cuantos valores vas a introducir: ";
                cin>>nValores;
                cout<<endl;

                v.rellenar(nValores);
                break;

            case 2:
                int elementos;
                elementos=v.getnElem();

                if(elementos>0)
                    {
                        v.mostrar();
                        cout<<endl;
                    }
                else
                    cout<<"El vector esta vacio"<<endl;

                break;

            case 3:
                int pos;

                cout<<"Introduce una posicion desde donde buscar el valor minimo: ";
                cin>>pos;

                if(pos<1 || pos>15)
                {
                    cout<<"Posicion invalida"<<endl;
                }
                else
                {
                    cout<<"El menor valor es: "<<v.menorRelativo(pos-1)<<endl;
                }

                break;

            case 4:
                {
                   int elemento=v.getnElem();

                    for(int i=0; i<elemento-1; i++)
                    {
                        for(int j=0; j<elemento-1-i; j++)
                        {
                            if(v.getValor(j) > v.getValor(j+1))
                            {
                                v.intercambio(j, j+1); // intercambia posiciones, no valores
                            }
                        }
                    }

                    cout << "Vector ordenado" << endl;
                    break;
                }


            case 5:
                cout<<"Saliendo del programa..."<<endl;
                break;


            default:cout<<"Opcion invalida"<<endl;
        }


   }while(op!=5);

   return 0;
}
