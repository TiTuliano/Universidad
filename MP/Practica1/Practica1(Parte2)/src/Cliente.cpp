#include <cstdlib>
#include <cstring>
#include <iomanip> //std::setprecision
#include <sstream> //stringstream
#include "Cliente.h"
#include <iostream>

using namespace std;

Cliente::Cliente(long int d, char *nom, Fecha f):fechaAlta(f)
{
  this->dni=d;
  this->nombre=new char[strlen(nom)+1];
  strcpy(this->nombre, nom);

}

Cliente::~Cliente()
{
  delete [] this->nombre; //si en el constructor uso new [] en el destructor uso delete []
}

Cliente& Cliente::operator=(const Cliente& c)
{
  if (this != &c)
    { //si no es x=x
        this->dni=c.dni;
        delete [] this->nombre;

        this->nombre=new char[strlen(c.nombre)+1];
        strcpy(this->nombre, c.nombre);

        this->fechaAlta=c.fechaAlta;
  }
  return *this;
}

Cliente::Cliente(const Cliente& c):fechaAlta(c.fechaAlta) //constructor de copia necesario siempre que en la clase tenga un *char
{
    this->nombre=new char[strlen(c.nombre)+1];
    strcpy(this->nombre, c.nombre);
    this->dni=c.dni;
}

bool Cliente::operator==(Cliente c) const
{
  if (this->dni!=c.dni)
    return false;

  if (strcmp(this->nombre, c.nombre)!=0)
    return false;

  if (this->fechaAlta.getDia()!=c.fechaAlta.getDia() ||
      this->fechaAlta.getMes()!=c.fechaAlta.getMes() ||
      this->fechaAlta.getAnio()!=c.fechaAlta.getAnio())

        return false;

  return true;
}

void Cliente::setNombre(char *nom)
{
    if (this->nombre != NULL)
        delete[] this->nombre;
    this->nombre = new char[strlen(nom) + 1];
    strcpy(this->nombre, nom);

}

void Cliente::setFecha(Fecha f)
{
    f.setFecha(f.getDia(),f.getMes(),f.getAnio());
}

ostream& operator<<(ostream &s, const Cliente &c)
{

  s<<"Nombre del cliente: "<<c.getNombre()<<endl
   <<"Dni: "<<c.getDni()<<endl;

    Fecha f = c.getFecha();

  s << "Fecha de alta: "
    << f.getDia() << "/"
    << f.getMes() << "/"
    << f.getAnio() << endl;

   return s;
}
