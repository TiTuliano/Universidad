#include "Cuenta.h"

Cuenta::Cuenta()
{
    Saldo = 0;
    NoCuenta = 0;
    Bloqueada = false;
}

Cuenta::Cuenta(int pNo,float pSal)
{
   Saldo = pSal;
   NoCuenta = pNo;
   Bloqueada = false;
}

bool Cuenta::ActualizarSaldo(int pSal)
{
    bool actualizado = false;

    if(Bloqueada == false)
    {
        Saldo = pSal;
        actualizado = true;
    }

    return actualizado;
}

void Cuenta::ActualizarBloqueo(bool pBloq)
{
    Bloqueada = pBloq;
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

