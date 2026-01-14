#include "ContratoTP.h"

int ContratoTP::minutosTP=300;
float ContratoTP::precioTP=10;
const float ContratoTP::precioExcesoMinutos=0.15;

ContratoTP::ContratoTP(long int dni, Fecha f, int m):Contrato()
{
    minutosHablados=m;
    fechaContrato=f;
    dniContrato=dni;
}

ContratoTP::ContratoTP(const ContratoTP& c):Contrato()
{
    this->minutosHablados=c.minutosHablados;
    dniContrato=c.getDniContrato();
    fechaContrato=c.getFechaContrato();
}

//static se pone en el .h (no se pone en el .cpp)
void ContratoTP::setTarifaPlana(int m, float p)
{
    ContratoTP::minutosTP=m; //puedo poner minutosTP=m ...pongo ContratoTP::minutosTP para recordar que es estatico
    ContratoTP::precioTP=p;  //puedo poner precioTP=p  ...pongo ContratoTP::precioTP para recordar que es estatico
}

float ContratoTP::factura() const
{
    if (minutosHablados <= minutosTP)
        return precioTP;
    else
        return precioTP + (minutosHablados - minutosTP) * precioExcesoMinutos;
}

ostream& operator<<(ostream &s, const ContratoTP &c)
{
    // Muestra los datos comunes del contrato (de la clase base)
    s << (Contrato &)c;

    // Luego, añade los datos específicos del contrato de tipo Tarifa Plana
    s << " " << c.getMinutosHablados() << "m, ";
    s << ContratoTP::getLimiteMinutos() << "m por " << ContratoTP::getPrecio() << "â‚¬, ";
    s << c.factura() << "â‚¬";

    return s;
}

void ContratoTP::ver() const
{
    Contrato::ver(); //IMPORTANTE: llamamos al ver que heredo de mi padre PARA QUE MUESTRE LO DEL PADRE
    //... y a continuacion solo "me preocupo" de mostrar lo que es exclusivo del hijo
    cout << " " << this->minutosHablados << "m, "<< minutosTP <<"("<< precioTP <<")"<<" - "<<factura()<<"â‚¬";
}

