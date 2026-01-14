#ifndef COMPLEJO_H
#define COMPLEJO_H


class complejo
{
    int real;
    int imaginario;
public:
    complejo(int r, int i);
    virtual ~complejo();
    int getr() const { return real; }
    int geti() const { return imaginario; }
    void set();
    void set(int real, int i);
    void ver() const;

    complejo operator+(complejo c) const;
    complejo operator+(int i) const;

    complejo operator-() const;

    //friend complejo operator+(int i, complejo c);

};

complejo operator+(int i, complejo c);

#endif // COMPLEJO_H
