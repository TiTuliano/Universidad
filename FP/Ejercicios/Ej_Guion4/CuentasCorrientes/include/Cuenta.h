#ifndef CUENTA_H
#define CUENTA_H


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

#endif // CUENTA_H
