#include "Empresa.h"

Empresa::Empresa()
{
    ncli=0;
    ncom=0;
    nmaxcom=10;

    //inicializo el array estatico de clientes a NULL
    for(int i=0; i<nmaxcli; i++)
    {
        clientes[i]=NULL;
    }

    //el array de contratos al ser dinamico hay que crearlo
    contratos=new Contrato* [nmaxcom];

    //inizializo todo a NULL
    for(int i=0; i<nmaxcom; i++)
    {
        contratos[i]=NULL;
    }
}

Empresa::~Empresa()
{
    //borramos los contratos
    for(int i=0; i<ncom; i++)
    {
        delete contratos[i];
    }
    //borramos el array
    delete[]contratos;

    //borramos los clientes pero no el array ya que este es estatico
    for(int i=0; i<ncli; i++)
    {
        delete clientes[i];
    }
}

int Empresa::buscarCliente(long int dni) const
{
    int pos=-1;
    for(int i=0; i<ncli && pos==-1; i++)
    {
        if(clientes[i]->getDni()==dni)
            pos=i;
    }
    return pos;
}

int Empresa::altaCliente(Cliente *c)
{
    if(ncli>=nmaxcli)
        return -1;

    clientes[ncli]=c;
    ncli++;

    return ncli-1;
}

void Empresa::ampliarContratos()
{
    Contrato **contratosNuevos=new Contrato* [nmaxcom*2];

    //copiamos el contenido del array original en el que se redimensiona
    for(int i=0; i<ncom; i++)
    {
        contratosNuevos[i]=contratos[i];
    }

    //el resto de posiciones las ponemos a null
    for(int i=ncom; i<nmaxcom*2; i++)
    {
        contratosNuevos[i]=NULL;
    }

    delete[]contratos;
    contratos=contratosNuevos;
    nmaxcom=nmaxcom*2;
}

void Empresa::crearContrato()
{
    long int dni;
    Cliente *c;
    int d, m, a;

    cout<<"Introdude el DNI del cliente: ";
    cin>>dni;

    //Buscamos si el cliente existe
    int posCliente=buscarCliente(dni);

    if(posCliente==-1) //Si se cumple hay que crear un cliente nuevo
    {
        if(ncli>=nmaxcli)
        {
            cout<<"No se pueden añadir mas clientes (lista llena)"<<endl;
            return;
        }

        char nombre[50];
        cout << "Cliente nuevo detectado.\n";
        cout << "Introduce nombre: ";
        cin.ignore();
        cin.getline(nombre, 50);
        cout << "Introduce la fecha de alta (dd mm aaaa): ";
        cin >> d >> m >> a;

        c=new Cliente(dni,nombre,Fecha(d,m,a));
        altaCliente(c);
    }
    else //si el cliente existe
    {
        c=clientes[posCliente];
        cout<<"Cliente encontrado: "<<c->getNombre()<<endl;
    }

    //Ahora que tenemos cliente elegimos que contrato vamos a crear
    int tipo;
    Contrato *nuevoContrato = NULL;

    do
    {
        cout << "Tipo de contrato (1=Tarifa Plana, 2=Movil): ";
        cin >> tipo;

        //creamos un contrato en funcion del tipo que se seleccione

        if(tipo==1) //ContratoTP
        {
            int minutos;
            cout<<"Introduce los minutos hablados ";
            cin>>minutos;
            cout << "Introduce la fecha del contrato (dd mm aaaa): ";
            cin >> d >> m >> a;
            Fecha f(d, m, a);
            cout<<endl;

            nuevoContrato=new ContratoTP(dni,f,minutos);
        }
        else if(tipo==2) //Contrato Movil
        {
            float precio;
            int minutos;
            char nacionalidad[30];
            cout << "Introduce los minutos hablados: ";
            cin >> minutos;
            cout << "Introduce el precio por minuto: ";
            cin >> precio;
            cout << "Introduce la nacionalidad: ";
            cin.ignore();
            cin.getline(nacionalidad, 30);
            cout << "Introduce la fecha del contrato (dd mm aaaa): ";
            cin >> d >> m >> a;
            cout<<endl;
            Fecha f(d, m, a);
            nuevoContrato = new ContratoMovil(dni, f, precio, minutos, nacionalidad);
        }
        else
        {
            cout<<"Tipo de contrato no valido"<<endl;
        }

    }
    while(tipo!=1 && tipo!=2);

    //Si el array de contratos esta lleno lo redimensionamos
    //Si no lo esta insertamos el contrato

    if(ncom>=nmaxcom)
    {
        ampliarContratos();
    }

    //añadimos el contrato al array
    if(nuevoContrato!=NULL)
    {
        contratos[ncom++]=nuevoContrato;
        cout<<"Contrato creado correctamente"<<endl;
    }

}

bool Empresa::cancelarContrato(int idContrato)
{

    if(ncom==0) //comprobamos que haya algun contrato a borrar
    {
        return false;
    }

    //recorremos el array de contratos para buscar

    int pos=-1;
    // Buscamos el contrato y salimos en cuanto lo encontremos
    for(int i=0; i<ncom && pos==-1; i++)
    {
        if(contratos[i]->getIdContrato()==idContrato)
        {
            pos=i;
        }
    }

    //no se encuentra
    if(pos==-1)
    {
        return false;
    }

    //lo hemos encontrado,entonces lo borramos
    delete contratos[pos];

    //Desplazamos los elementos del array 1 posicion a la izquierda
    for(int i=pos; i<ncom-1; i++)
    {
        contratos[i]=contratos[i+1];
    }

    ncom--; //reducimos el numero de contratos
    return true;
}

bool Empresa::bajaCliente(long int dni)
{
    //Buscamos cliente
    int posCliente=buscarCliente(dni);
    if(posCliente==-1) //no esta
    {
        cout<<"El cliente no existe"<<endl;
        return false;
    }
    //como esta eliminamos todos los contratos que tenga el cliente
    for(int i=0; i<ncom;)
    {
        if(contratos[i]->getDniContrato()==dni)
        {
            delete contratos[i]; //borramos
            //desplazamos los demas hacia la izq
            for(int j=i; j<ncom-1; j++)
            {
                contratos[j]=contratos[j+1];

            }
            //un contrato menos por lo que decrementamos
            ncom--;
        }
        else
        {
            i++;
        }
    }

    //eliminamos el cliente
    delete clientes[posCliente];

    //movemos los clientes 1 posicion a la izq
    for(int i=posCliente; i<ncli-1; i++)
    {
        clientes[i]=clientes[i+1];
    }

    //decrementamos el num de clientes
    ncli--;
    return true;
}

int Empresa::descuento(float porcentaje) const
{
    int contador=0;
    for (int i=0; i<ncom; i++)
    {
        ContratoMovil *cm=dynamic_cast<ContratoMovil*>(contratos[i]);
        if (cm!=NULL)
        {
            float precioActual=cm->getPrecioMinuto();
            float nuevoPrecio=precioActual*(1-porcentaje/100);
            cm->setPrecioMinuto(nuevoPrecio);
            contador++;
        }
    }
    return contador;
}


int Empresa::nContratosTP() const
{
    int contador = 0;
    for (int i = 0; i < ncom; i++)
    {
        ContratoTP *tp = dynamic_cast<ContratoTP*>(contratos[i]);
        if (tp != NULL)
        {
            contador++;
        }
    }
    return contador;
}

void Empresa::cargarDatos()
{
    // Crear clientes
    clientes[0] = new Cliente(75547001, "Peter Lee", Fecha(28, 2, 2001));
    clientes[1] = new Cliente(45999000, "Juan Perez", Fecha(29, 2, 2000));
    clientes[2] = new Cliente(37000017, "Luis Bono", Fecha(31, 1, 2002));
    ncli = 3;

    // Reservamos espacio inicial para contratos
    nmaxcom = 10;
    contratos = new Contrato*[nmaxcom];
    ncom = 0;

    // Crear contratos mezclados TP y Móvil
    contratos[ncom++] = new ContratoMovil(75547001, Fecha(28, 2, 2001), 0.12f, 110, "DANES");
    contratos[ncom++] = new ContratoMovil(75547001, Fecha(31, 1, 2002), 0.09f, 170, "DANES");
    contratos[ncom++] = new ContratoTP(37000017, Fecha(1, 2, 2002), 250);
    contratos[ncom++] = new ContratoTP(75547001, Fecha(28, 2, 2001), 312);
    contratos[ncom++] = new ContratoMovil(45999000, Fecha(31, 1, 2002), 0.10f, 202, "ESPAÑOL");
    contratos[ncom++] = new ContratoMovil(75547001, Fecha(31, 1, 2002), 0.15f, 80, "DANES");
    contratos[ncom++] = new ContratoTP(45999000, Fecha(1, 2, 2002), 400);
}


void Empresa::ver() const
{
    cout << "La Empresa tiene " << ncli << " clientes y " << ncom << " contratos\n";

    cout << "Clientes:\n";
    for (int i = 0; i < ncli; i++)
    {
        cout<<*clientes[i]; // le ponemos * para que muestre el cliente y no la direccion de memoria
        cout << endl;
    }

    cout << "\nContratos:\n";
    for (int i = 0; i < ncom; i++)
    {
        contratos[i]->ver(); // llamamos al método ver de ContratoTP o ContratoMovil
        cout << endl;
    }
}




