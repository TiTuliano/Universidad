#ifndef CONTRATO_H
#define CONTRATO_H

#include <iostream> //cin, cout
#include "Fecha.h"

using namespace std;

class Contrato
{
protected:
  static int contador;
  const int idContrato;
  long int dniContrato;
  Fecha fechaContrato;
public:
  Contrato():idContrato(Contrato::contador){Contrato::contador++;};
  virtual ~Contrato();
//Contrato(const Contrato& c); //¿es necesario? pensar y reflexionad

//Contrato& operator=(const Contrato& c); //no es necesario y ademas no puede ser usado porque Contrato tiene un
                                          //atributo constante idContrato que no puede modificarse
                                          //no se puede usar el = en el main con objetos Contrato

  virtual int getIdContrato() const=0;
  virtual long int getDniContrato() const=0;
  virtual Fecha getFechaContrato() const=0;
  virtual void setFechaContrato(Fecha f)=0;
  virtual void setDniContrato(long int dni)=0;
  virtual void ver() const=0; //virtual para hacer al metodo polimorfico
};

ostream& operator<<(ostream &s, const Contrato &c);

#endif // CONTRATO_H

