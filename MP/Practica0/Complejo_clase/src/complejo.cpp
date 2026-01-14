#include "complejo.h"
#include <iostream>

using namespace std;

complejo::complejo(int real, int i)
{
    this->real=real;
    imaginario=i;
}

complejo::~complejo()
{
    //dtor
}

void complejo::set(int r, int i)
{
    real=r;
    imaginario=i;
}

void complejo::set()
{
    cout<<"Introduzca la parte real: ";
    cin>>real;
    cout<<"Introduzca la parte imaginaria: ";
    cin>>imaginario;
}

void complejo::ver() const
{
    if(imaginario>=0)
    {
        cout<<real<<"+"<<imaginario<<endl;
    }
    else
    {
        cout<<real<<imaginario<<endl;
    }
}

complejo complejo::operator+(complejo otro) const
{
    complejo suma(0,0);
    suma.real=real+otro.real;
    suma.imaginario=imaginario+otro.imaginario;

    return suma;
}

complejo complejo:: operator+(int a) const
{
    complejo suma(real+a,imaginario);
    return suma;
}

complejo complejo::operator-() const
{
    complejo negado(-real,-imaginario);
    return negado;
}

complejo operator+(int r,complejo otro)
{
    return otro+r;
}
