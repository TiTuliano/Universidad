#include <iostream>
#include "complejo.h"
#include "complejo.h"

using namespace std;

complejo::complejo(int r, int i) {
    real=r;
    imaginario=i;
}

complejo::~complejo()
{
    //dtor
}

void complejo::set() {
    cout << "Valor parte real: ";
    cin >> real;
    cout << "Valor parte imaginaria: ";
    cin >> imaginario;
}

void complejo::set(int real, int i) {
    this->real=real; //complejo::real=real;
    imaginario=i;
}

void complejo::ver() const {
    if (imaginario>=0) {
        cout << real << "+" << imaginario << "i" << endl;
    }
    else {
        cout << real << imaginario << "i" << endl;
    }
}

complejo complejo::operator+(complejo c) const {
    complejo suma(0,0);
    suma.real=real+c.real;
    suma.imaginario=imaginario+c.imaginario;
    return suma;
}

complejo complejo::operator+(int i) const {
    complejo suma(real+i,imaginario);
    return suma;
}

complejo operator+(int i, complejo c) {
//complejo suma(0,0);
    //suma.real=c.real+i;
    //suma.imaginario=c.imaginario;
    ///////suma.real=c.getr()+i;
    ///////suma.imaginario=c.geti();

//suma.set(c.getr()+i, c.geti());
//return suma;


    return c+i; // return c.operator+(i);
}


 complejo complejo::operator-() const {
    complejo copia(-real, -imaginario);
    return copia;
 }
