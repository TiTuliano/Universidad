
//MAIN PRACTICA 1

/*#include <cstdlib>
    #include <iostream>
    #include "Fecha.h"   // definición de la clase Fecha
    #include "Cliente.h" // definición de la clase Cliente

    using namespace std;

    int main() {
        Fecha f1(29, 2, 2001), f3(29, 2, 2004), f4(29, 2, 1900);
        // Fecha f5; // no permitido

        const Fecha f2 = f1; // indica que método se está ejecutando aquí (constructor de copia)

        f1.setFecha(f3.getDia() - 3, f3.getMes() - 2, 2007); // 29-3/2-2/2007 --> f1 = 26/1/2007

        cout << "Fechas: ";
        f1.ver(); cout << ", ";
        f2.ver(); cout << ", ";
        f3.ver(); cout << ", ";
        f4.ver(); cout << endl;

        if (f3.bisiesto() && !f2.bisiesto() && f4.bisiesto() == false)
            cout << f3.getAnio() << " es bisiesto, "
                 << f2.getAnio() << " y " << f4.getAnio() << " no\n";

        f4.setFecha(31, 12, 2000); // f4 = 31/12/2000
        f3 = f4++;                 // operador postincremento
        ++f4;                      // operador preincremento

        f1 = 2 + f2 + 3;

        cout << "Fechas: ";
        f1.ver(); cout << ", ";
        f2.ver(); cout << ", ";
        f3.ver(); cout << ", ";
        f4.ver(); cout << endl;

       Cliente *p = new Cliente(75547001, "Susana Diaz", f1);

        f1.setFecha(7, 10, 2015);

        Cliente c(75547999, "Juan Sin Miedo", Fecha(29, 2, 2000));
        const Cliente j(44228547, "Luis", f1);

       c.setNombre("Juan Palomo");

        if (j == c)
            cout << "\nj y c son iguales\n";
        else
            cout << "\nj y c no son iguales\n";

       cout << p->getDni() << " - " << c.getNombre() << ": " << j.getFecha() << endl;

       cout << *p << "\n" << c << "\n" << j << "\n";

        c = *p;
        p->setNombre("Susanita");
        p->setFecha(p->getFecha() + 10);

        cout << "\nDatos de los clientes: \n";
        cout << *p << "\n" << c << "\n" << j << "\n";

        delete p;
        p = NULL;

        system("PAUSE");
        return 0;
    }
*/


//MAIN PRACTICA 2

/*#include <cstdlib>
#include <iostream>
#include <iomanip>    // std::setprecision
#include "Fecha.h"    // Definición de la clase Fecha
#include "Contrato.h" // Definición de la clase Contrato
#include "ContratoTP.h" // Definición de la clase ContratoTP
#include "ContratoMovil.h" // Definición de la clase ContratoMovil

using namespace std;

int main(int argc, char *argv[])
{

    Fecha f1(29, 2, 2001), f2(f1), f3(29, 2, 2004);
    cout << "Fechas: ";
    f1.ver(); cout << ", ";
    f2.ver(); cout << ", ";
    f3.ver(); cout << endl;

    //Contrato *p = new Contrato(75547111, f1), c(23000111, Fecha(2, 2, 2002)); //como ahora la clase contrato es abstracta esto da error
                                                                                //ya que no se pueden crear objetos de la clase contrato de manera directa
                                                                                //todo lo que influya a c y p da error de compilacion

    cout << ContratoTP::getLimiteMinutos() << " - " << ContratoTP::getPrecio() << endl;

    ContratoTP ct1(17333256, f1, 250);  // Habla 250 minutos
    ContratoTP ct2(12555100, f3, 320);  // Habla 320 minutos
    ContratoTP ct3(ct1);

    ContratoMovil cm1(17333256, f1, 0.12, 100, "ESPAÃ‘OL"); // Habla 100 minutos
    ContratoMovil cm2(17000000, Fecha(3, 3, 2003), 0.10, 180, "FRANCES"); // Habla 180 minutos
    ContratoMovil cm3(cm2);

    //p->ver(); cout << "\n";
    //c.ver(); cout << endl;

    ct1.ver(); cout << endl;
    ct2.ver(); cout << "\n";
    ct3.ver(); cout << "\n";

    cm1.ver(); cout << endl;
    cm2.ver(); cout << "\n";
    cm3.ver(); cout << "\n";

    //cout << p->getIdContrato() << ct2.getIdContrato() << cm2.getIdContrato() << endl;

    cout << setprecision(2) << fixed; // A partir de aquí float se muestra con 2 decimales

    cout << "Facturas: " << ct1.factura() << "-" << ct2.factura() << "-" << cm1.factura() << endl;

    ContratoTP::setTarifaPlana(350, 12); // 350 minutos por 12 euros

    //p->setDniContrato(cm1.getDniContrato());
    //ct3.setFechaContrato(p->getFechaContrato() + 1);
    cm3.setNacionalidad(cm1.getNacionalidad());
    cm2.setPrecioMinuto(cm1.getPrecioMinuto() + 0.02);
    cm1.setMinutosHablados(ct2.getMinutosHablados() / 2);
    ct1.setMinutosHablados(cm3.getMinutosHablados() * 2);

    //cout << *p << "\n" << c << endl;
    cout << ct1 << endl
         << ct2 << "\n"
         << ct3 << "\n"
         << cm1 << "\n"
         << cm2 << endl
         << cm3 << endl;
    Contrato *t[2]; //aqui en vez de 4 debemos de poner 2 ya que p y c no se pueden crear al ser contrato abstracta
    //t[0] = p;
    //t[1] = &c;
    t[0] = &ct2;
    t[1] = &cm1;

    cout << "\n-- Datos de los contratos: --\n";

    //cambiamos todos los indices para no irnos a una posicion invalida
    t[1]->setDniContrato(75547111);

    for (int i = 0; i < 2; i++) {
        t[i]->setFechaContrato(t[i]->getFechaContrato() + 2);
        t[i]->ver();
        cout << endl;
}


    system("PAUSE");
    return 0;
}
*/

//MAIN PRACTICA 3

#include <cstdlib>
#include <iostream>
#include <iomanip>    // std::setprecision
#include "Fecha.h"    // definicion clase Fecha
#include "Cliente.h"  // definicion clase Cliente
#include "Contrato.h" // definicion de la clase Contrato
#include "ContratoTP.h" // definicion de la clase ContratoTP
#include "ContratoMovil.h" // definicion de la clase ContratoMovil
#include "Empresa.h"  // definicion de la clase Empresa

using namespace std;

int main(int argc, char *argv[])
{
    bool ok;
    Empresa Yoigo;

    cout << setprecision(2) << fixed; // a partir de aqui float se muestra con 2 decimales
    cout << endl << "APLICACION DE GESTION TELEFONICA\n" << endl;

    Yoigo.cargarDatos(); // crea 3 clientes y 7 contratos. metodo creado para no
    Yoigo.ver();          // tener que meter datos cada vez que pruebo el programa

    cout << "Yoigo tiene " << Yoigo.nContratosTP() << " Contratos de Tarifa Plana\n\n";

    Yoigo.crearContrato(); // ContratoMovil a 37000017 el 01/01/2017 con 100m a 0.25
    Yoigo.crearContrato(); // ContratoTP a 22330014 (pepe luis) el 2/2/2017 con 305m

    // ESTA LINEA HACE QUE ME DE ERROR EN LA MEMORIA
    ok = Yoigo.cancelarContrato(28); // este Contrato no existe
    if (ok)
        cout << "Contrato 28 cancelado\n";
    else
        cout << "El Contrato 28 no existe\n";

    ok = Yoigo.cancelarContrato(4); // este Contrato si existe
    if (ok)
        cout << "El Contrato 4 ha sido cancelado\n";
    else
        cout << "El Contrato 4 no existe\n";

    ok = Yoigo.bajaCliente(75547001); // debe eliminar el cliente y sus 3 Contratos
    if (ok)
        cout << "El cliente 75547001 y sus Contratos han sido cancelados\n";
    else
        cout << "El cliente 75547001 no existe\n";

    Yoigo.ver();

    Yoigo.descuento(20);
    cout << "\nTras rebajar un 20% la tarifa de los ContratosMovil..."<<endl;
    Yoigo.ver();

    cout << "Yoigo tiene " << Yoigo.nContratosTP() << " Contratos de Tarifa Plana\n";

    system("PAUSE");
    return 0;
}

