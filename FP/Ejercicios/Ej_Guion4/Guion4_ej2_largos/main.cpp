#include <iostream>

using namespace std;
typedef char Cadena[50]; // Tipo de datos Cadena
#define MAX_CUENTAS 100 // Número de Cuentas

class Cuenta //Contiene los datos de una cuenta bancaria
{
    float Saldo; // Saldo de la cuenta
    int NoCuenta; // Número de la cuenta
    bool Bloqueada; // true si está bloqueada
    public:
    Cuenta();
    Cuenta(int pNo, float pSal);
    bool ActualizarSaldo(int pSal);
    void ActualizarBloqueo(bool pBloq);
    float DameSaldo();
    int DameNoCuenta();
    bool EstaBloqueada();
};
 Cuenta::Cuenta()
 {
     Saldo=0;
     NoCuenta=0;
     Bloqueada=0;
 }

Cuenta::Cuenta(int pNo,float pSal)
{
    Saldo=pSal;
    NoCuenta=pNo;
    Bloqueada=false;
}

bool Cuenta::ActualizarSaldo(int pSal)
{
    bool actualizado=false;
    if(Bloqueada==false)
    {
        Saldo=pSal;
        actualizado=true;
    }

    return actualizado;
}

void Cuenta::ActualizarBloqueo(bool pBloq)
{
    Bloqueada=pBloq;
}

float Cuenta::DameSaldo()
{
    return Saldo;
}

int Cuenta::DameNoCuenta()
{
    return NoCuenta;
}

bool Cuenta::EstaBloqueada()
{
    return Bloqueada;
}

int BuscarCuenta(Cuenta Ctas[MAX_CUENTAS], int NCuentas, int NoCuenta)
{
    int i=-1;
    int numCuenta;

    for(int j=0; j<=NCuentas; j++)
    {
        numCuenta=Ctas[j].DameNoCuenta();
        if(numCuenta==NoCuenta)
        {
            i=j;
        }

    }
    return i;
}

int MenuCuentas()
{
    cout<<"--- Menu Gestion de Cuentas ---"<<endl
    <<"1. Anadir una cuenta a un cliente"<<endl
    <<"2. Mostrar las cuentas del cliente"<<endl
    <<"3. Borrar una cuenta del cliente"<<endl
    <<"4. Modificar saldo de una cuenta"<<endl
    <<"5. Modificar estado de una cuenta"<<endl
    <<"6. Salir"<<endl
    <<"Elige Opcion: ";
}



int main()
{
    Cuenta DatosCuentas[MAX_CUENTAS];
    Cuenta c;
    int nCuentas = 0;
    int op;

    do
    {
        MenuCuentas();
        cin>>op;

        switch(op)
        {
            case 1:
                if(nCuentas<MAX_CUENTAS)
                {
                    int num;
                    float saldoIni;
                    bool noExiste=false;

                    cout<<"Introduce el numero de la nueva cuenta: ";
                    cin>>num;

                    for(int i=0; i<nCuentas; i++)
                    {
                        if(DatosCuentas[i].DameNoCuenta()==num)
                        {
                            cout<<"Error. Ya existe una cuenta con ese numero."<<endl;
                            noExiste=true;
                        }

                    }

                    if(noExiste==false)
                    {
                        cout<<"Introduce el saldo inicial de la cuenta: ";
                        cin>>saldoIni;

                        DatosCuentas[nCuentas]=Cuenta(num,saldoIni);
                        nCuentas++;
                    }
                }

                break;

            case 2:

                bool bloqueda;

                for(int i=0; i<nCuentas; i++)
                {
                    cout<<"Cuenta "<<i+1<<endl;
                    cout<<"Numero de cuenta: "<<DatosCuentas[i].DameNoCuenta()<<endl;
                    cout<<"Saldo: "<<DatosCuentas[i].DameSaldo()<<endl;

                    bloqueda=DatosCuentas[i].EstaBloqueada();
                    if(bloqueda==true)
                    {
                        cout<<"Estado de bloqueo: bloqueada"<<endl;
                    }
                    else
                        cout<<"Estado de bloqueo: No bloqueada"<<endl;


                }
                break;

            case 3:
                {
                    int numBorrar, j=0;
                    bool encontrado=false;

                    cout<<"Introduce el numero de cuenta a borrar: ";
                    cin>>numBorrar;

                    while(!encontrado && j<nCuentas)
                    {
                        if(DatosCuentas[j].DameNoCuenta()==numBorrar)
                            encontrado=true;
                        else
                            j++;
                    }

                    if(encontrado==true)
                    {
                         for(int i=j; i<nCuentas-1; i++)
                            {
                                DatosCuentas[i]=DatosCuentas[i+1];
                            }

                        nCuentas--;
                        cout<<"Cuenta borrada"<<endl;
                    }

                    else
                        cout<<"Error. No existe una cuenta con el numero introducido"<<endl;

                    break;
                }



            case 4:
                {
                    int numActualizar, j=0;
                    bool encontrado=false;
                    int saldo;

                    cout<<"Introduce el numero de cuenta a actualizar: ";
                    cin>>numActualizar;

                    cout<<"Introduce nuevo saldo: ";
                    cin>>saldo;

                    while(!encontrado && j<nCuentas)
                    {
                        if(DatosCuentas[j].DameNoCuenta()==numActualizar)
                            encontrado=true;
                        else
                            j++;
                    }

                    if(encontrado==true)
                    {
                        DatosCuentas[j].ActualizarSaldo(saldo);
                        cout<<"Saldo actualizado"<<endl;
                    }

                    else
                        cout<<"Error."<<endl;

                    break;
                }

            case 5:
                {
                    int numActualizar, j=0;
                    bool encontrado=false;
                    char decision;
                    bool bloqueado=false;


                    cout<<"Introduce el numero de cuenta para cambiar el estado de la cuenta: ";
                    cin>>numActualizar;

                    while(!encontrado && j<nCuentas)
                    {
                        if(DatosCuentas[j].DameNoCuenta()==numActualizar)
                            encontrado=true;
                        else
                            j++;
                    }

                    if(encontrado==true)
                    {
                        cout<<"Introduce s para cambiar estado o n para cancelar: ";
                        cin>>decision;
                        if(decision=='s')
                        {
                            if(DatosCuentas[j].EstaBloqueada()==false)
                            {
                                bloqueado=true;
                                DatosCuentas[j].ActualizarBloqueo(bloqueado);
                                cout<<"Estado actualizado"<<endl;
                            }
                            else
                            {
                                bloqueado=false;
                                DatosCuentas[j].ActualizarBloqueo(bloqueado);
                                cout<<"Estado actualizado"<<endl;
                            }
                        }
                    }

                    else
                        cout<<"Error."<<endl;

                    break;
                }


            case 6:
                cout<<"Saliendo del programa..."<<endl;
                break;


            default:cout<<"Opcion invalida. Intentalo de nuevo."<<endl;

        }

    }while(op!=6);

    return 0;
}
