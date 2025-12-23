#include <iostream>
#include "Cuenta.h"

using namespace std;

int BuscarCuenta(Cuenta Ctas[MAX_CUENTAS], int NCuentas, int NoCuenta);
int MenuCuentas();

int main()
{
    Cuenta DatosCuentas[MAX_CUENTAS];
    int nCuentas = 0; //Nº de elementos del vector DatosCuentas
    int op;

    do
    {
        MenuCuentas();
        cin >> op;

        switch(op)
        {
        case 1:
        {
            int numCuenta;
            float sal;

            if(nCuentas < MAX_CUENTAS)
            {
                cout << "Introduce el numero de su nueva cuenta: ";
                cin >> numCuenta;

                if(BuscarCuenta(DatosCuentas, nCuentas, numCuenta) == -1)
                {
                    cout << "Introduzca el saldo de esta cuenta: ";
                    cin >> sal;

                    DatosCuentas[nCuentas] = Cuenta(numCuenta,sal);
                    nCuentas++;

                }
                else
                    cout << "Error. Ya hay una cuenta con el numero: " << numCuenta << endl;

            }
            else
                cout << "Error. Ya no se pueden almacenar mas cuentas." << endl;

            break;
        }


        case 2:
        {
            if(nCuentas == 0)
            {
                cout << "No hay ninguna cuenta" << endl;
            }
            else
            {
                for(int i = 0; i < nCuentas; i++)
                {
                    cout << endl
                         << "Cuenta " << i + 1 << endl
                         << "Numero de Cuenta: " << DatosCuentas[i].DameNoCuenta() << endl
                         << "Saldo: " << DatosCuentas[i].DameSaldo() << endl
                         << "Estado: ";

                    if(DatosCuentas[i].EstaBloqueada())
                        cout << "Bloqueda";
                    else
                        cout << "Acitva";

                    cout << endl << endl;
                }
            }


            break;
        }


        case 3:
        {
            int cuentaBorrar, pos = -1;

            cout << "Introduce el numero de cuenta a borrar: ";
            cin >> cuentaBorrar;

            pos = BuscarCuenta(DatosCuentas, nCuentas, cuentaBorrar);

            if(pos != -1)
            {
                for (int i = pos; i < nCuentas; i++)
                {
                    DatosCuentas[i] = DatosCuentas[i+1];
                }

                nCuentas--;

                cout << "Cuenta eliminada con exito" << endl;
            }
            else
                cout << "Error no hay ninguna cuenta con numero: " << cuentaBorrar << endl;

            break;
        }

        case 4:
        {
            int numCuenta2, sal2, pos;

            cout << "Introduce el numero de la cuenta a actualizar: ";
            cin >>numCuenta2;

            pos = BuscarCuenta(DatosCuentas, nCuentas, numCuenta2);

            if( pos != -1)
            {
                if(DatosCuentas[pos].EstaBloqueada() == false)
                {
                    cout << "Introduzca el nuevo saldo de esta cuenta: ";
                    cin >> sal2;

                    DatosCuentas[pos].ActualizarSaldo(sal2);
                }
                else
                    cout << "Error. No se puede actualizar el saldo porque la cuenta esta bloqueada" << endl;

            }
            else
                cout << "Error no hay ninguna cuenta con numero: " << numCuenta2 << endl;

            break;

        }

        case 5:
        {
            int numCuenta3, pos;
            char letra;
            bool bloqueo;

            cout << "Introduce el numero de la cuenta a actualizar: ";
            cin >>numCuenta3;

            pos = BuscarCuenta(DatosCuentas, nCuentas, numCuenta3);

            if( pos != -1)
            {
                cout << "Desea actualizar el estado de la cuenta (s/n): ";
                cin >> letra;
                if(letra == 's')
                {
                    bloqueo = DatosCuentas[pos].EstaBloqueada();

                    if(bloqueo == true)
                        bloqueo = false;
                    else
                        bloqueo = true;

                    DatosCuentas[pos].ActualizarBloqueo(bloqueo);

                    cout << "Estado cambiado con exito" << endl;
                }
                else
                    cout << "Actualizacion cancelada" << endl;

            }
            else
                cout << "Error no hay ninguna cuenta con numero: " << numCuenta3 << endl;

            break;
        }

        case 6:
        {
            cout << "Saliendo del programa..." << endl;
            break;
        }

        default:
            cout << "Error. Elige una opcion correcta." << endl;

        }

    }
    while(op != 6);


    return 0;
}

int BuscarCuenta(Cuenta Ctas[MAX_CUENTAS], int NCuentas, int NoCuenta)
{
    int i = 0, pos = -1;
    bool encontrado = false;

    while(!encontrado && i<NCuentas)
    {
        if(Ctas[i].DameNoCuenta() == NoCuenta)
        {
            encontrado = true;
            pos = i;
        }
        else
            i++;
    }

    return pos;
}

int MenuCuentas()
{
    cout << endl
         <<"--- Menu Gestion de Cuentas ---" << endl
         << "1. Añadir una cuenta a un cliente" << endl
         << "2. Mostrar las cuentas del cliente" << endl
         << "3. Borrar una cuenta del cliente" << endl
         << "4. Modificar saldo de una cuenta" << endl
         << "5. Modificar estado de una cuenta" << endl
         << "6. Salir" <<endl
         << "Elige una opcion: ";
}
