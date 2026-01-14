#ifndef COMPLEJO_H
#define COMPLEJO_H


class complejo
{
    public:
        complejo(int real,int i);
        virtual ~complejo();

        int getr() const {return real;};
        int geti() const {return imaginario;};

        void set(int r, int i);
        void set();

        void ver() const;

        complejo operator+(complejo otro) const;
        complejo operator+(int a) const;

        complejo operator-() const;

    protected:

    private:
        int real;
        int imaginario;
};

complejo operator+(int r,complejo otro);

#endif // COMPLEJO_H
