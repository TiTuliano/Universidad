#include <iostream>
#include<cstring>

using namespace std;
typedef char cad[20];

class tprod
{
    cad nombre; // Nombre del producto
    float precio; // Precio del producto
    int stock; // Cantidad de producto en el almacén

    public:
        tprod();
        void cambiarnombre(cad nom);
        // Recibe nom como parámetro y lo copia en el atributo nombre.
         void cambiarprecio(float prec);
        // Recibe prec como parámetro y lo copia en el atributo precio.
         void cambiarstock(int stoc);
        // Recibe stoc como parámetro y lo copia en el atributo stock.
         void leenombre (cad nom);
        // Devuelve en el parámetro nom el valor del atributo nombre.
         float leeprecio ();
        // Devuelve el contenido del atributo precio.
         int leestock();
        // Devuelve el contenido del atributo stock.
         bool vender(int cantidad, float &total);
        /* Simula la venta del producto, quitando del stock la cantidad pasada como parámetro, además
         devolverá en total el precio a cobrar (precio unitario * cantidad vendida). Si la venta se ha podido realizar
         ( hay suficiente cantidad en el stock) el método devolverá true, en caso contrario devolverá false. */
};

tprod::tprod()
{
    strcpy(nombre,"NO HAY PRODUCTOS");
    precio=0;
    stock=0;
}

void tprod::cambiarnombre(cad nom)
{
   strcpy(nombre,nom);
}

void tprod::cambiarprecio(float prec)
{
    precio=prec;
}

void tprod::cambiarstock(int stoc)
{
    stock=stoc;
}

void tprod::leenombre(cad nom)
{
    strcpy(nombre,nom);
}

float tprod::leeprecio()
{
    return precio;
}

int tprod::leestock()
{
    return stock;
}

bool tprod::vender(int cantidad, float &total)
{
    bool exito=false;
    if(cantidad<=stock)
    {
        stock=stock-cantidad;
        total=precio*cantidad;
        exito=true;
    }
    else
    {
        total=0;
        cout<<"Error. No hay stock suficiente."<<endl;

    }

    return exito;
}

#define MAX 5
class almacen
{
    tprod productos[MAX];
    int nprod; //Nº de objetos tipo tprod almacenados en productos
    public:
        almacen(); /* Constructor que pondrá el almacén vacío */
        void vaciar(); /* Pondrá el almacén vacío */
        int existe(cad nom);
        /* Recibe el nombre de un producto como parámetro y devuelve en qué posición de la tabla se encuentra almacenado o bien -1 si no está. */
         void verprod (int pos, tprod &prod);
        /* Copia en prod el contenido del producto que se encuentra en la posición pos de la tabla de productos. */
         int insertar(tprod P);
        /* Intentará insertar un nuevo producto P pasado como parámetro en la tabla de productos, y devolverá:
        • 2, si la tabla está llena.
        • 1, si ya existe el producto (no se insertará de nuevo).
        • 0, si lo ha podido insertar. */
         void vertabla ();
        /* Visualiza por pantalla el contenido del almacén. Cada producto deberá mostrarse en una línea diferente con su nombre, precio y stock.
        Si el almacén está vacío expresará esta situación por pantalla. */
         bool vender (int pos, int cant, float &total);
        /* Intentará realizar la venta de una cantidad cant del producto que está en la posición pos de la tabla. Devolverá true o false
         en función de que se haya podido o no realizar la venta. */

};

almacen::almacen()
{
    nprod=0;
}

void almacen::vaciar()
{
    nprod=0;
}

int almacen::existe(cad nom)
{
    cad aux;
    int pos=-1;

    for(int i=0; i<nprod; i++)
    {
        productos[i].leenombre(aux);
        if(strcmp(aux,nom)==0)
        {
           pos=i;
        }
    }

    return pos;
}

void almacen::verprod(int pos, tprod &prod)
{
    if(pos>=0 && pos<nprod)
    {
        prod=productos[pos];
    }

}

int almacen::insertar(tprod P)
{
    int insertado=-1;
    cad aux;
    P.leenombre(aux);

    if(nprod==MAX)
    {
        insertado=2;
    }

    else if(existe(aux)!=-1)
    {
        insertado=1;
    }

    else
    {
       productos[nprod]=P;
       nprod++;
       insertado=0;
    }

    return insertado;

}

void almacen::vertabla()
{
    cad nombre;
    if(nprod==0)
    {
        cout<<"Error. No hay productos en el almacen."<<endl;
    }else
    {
        cout<<"PRODUCTOS DEL ALMACEN:  "<<endl;
        for(int i=0; i<nprod; i++)
            {
             productos[i].leenombre(nombre);
                 cout<<"Nombre: "<<nombre<<endl
                 <<"Precio: "<<productos[i].leeprecio()<<endl
                 <<"Stock: "<<productos[i].leestock()<<endl;
            }
    }

}

bool almacen::vender(int pos, int cant,float &total)
{
    bool vendido=false;

    if(pos<0 || pos>nprod)
    {
        cout<<"Error. No hay productos en esa posicion"<<endl;
        total=0;
    }
    else
    {
       productos[pos].vender(cant, total);
       vendido=true;
    }

    return vendido;
}

char menu()
{
    cout<<"MENU"<<endl
        <<"A.Visualizar la tabla"<<endl
        <<"B.Insertar un producto"<<endl
        <<"C.Vender un producto"<<endl
        <<"D.Vaciar el almacen"<<endl
        <<"E.Salir"<<endl
        <<"Elige una opcion: ";

}

int main()
{
    char op;
    almacen A;

    // Crear 3 productos
    tprod p1, p2, p3;

    p1.cambiarnombre("Melon"); p1.cambiarprecio(1.5); p1.cambiarstock(20);
    p2.cambiarnombre("Peras");    p2.cambiarprecio(2.0); p2.cambiarstock(15);
    p3.cambiarnombre("Naranjas"); p3.cambiarprecio(1.2); p3.cambiarstock(30);

    // Insertar productos en el almacén
    A.insertar(p1);
    A.insertar(p2);
    A.insertar(p3);

    do
    {
        menu();
        cin>>op;

        switch(op)
        {
            case 'A':

                A.vertabla();
                break;

            case 'a':

                A.vertabla();
                break;

            case 'B':


                break;

            case 'D':
                A.vaciar();
                break;

            case 'd':
                A.vaciar();
                break;



            default: cout<<"Error"<<endl;
                     break;

        }


    }while(op!='e' && op!='E');




    return 0;
}
