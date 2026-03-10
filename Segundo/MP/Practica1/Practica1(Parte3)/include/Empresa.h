#ifndef EMPRESA_H
#define EMPRESA_HCon

#include "Fecha.h"
#include "Cliente.h"
#include "ContratoTP.h"
#include "Contrato.h"
#include "ContratoMovil.h"

using namespace std;

class Empresa
{
    Cliente *clientes[100]; //array estatico de punteros a clientes
    int ncli; //para saber cuantos clientes hay en el array (empieza en 0)
    const int nmaxcli=100; //indica cuantos clientes caben en el array (100)
    Contrato **contratos; //array dinamico de punteros a contratos (capacidad ilimitada)
    int ncom; //para saber cuantos contratos caben en el array en un momento determinado
    int nmaxcom; //para saber el maximo de contratos que caben en el  array (variable)

    protected: //metodos auxiliares que seran usados por los metodos publicos
        int buscarCliente(long int dni) const;
        int altaCliente(Cliente *c); //añade el cliente apuntado por c al array de clientes
        void ampliarContratos();

    public:
        Empresa();
        virtual ~Empresa();
        //EL CONTRUCTOR DE COPIA Y EL OPERADOR DE ASIGNACION NO LO IMPLEMENTAMOS
        //PORQUE EXPLICITAMENTE SE INDICA EN LA PRACTICA QUE NO SE HAGA

        void crearContrato();
        bool cancelarContrato(int idContrato);
        bool bajaCliente(long int dni);
        int descuento (float porcentaje) const;
        int nContratosTP() const;
        void ver() const;
        void cargarDatos();//crea 3 clientes y 7 contratos para no meterlos manualmente
                           //cade vez que pruebe el programa
};

#endif // EMPRESA_H
