#include <iostream>
#include "complejo.h"

using namespace std;

int main() {
    complejo a(2,-3), b(5,0);
    const complejo c(4,7);
    a.ver();
    b.ver();
    a.set(7,4);
    b.set();
    a.ver();
    b.ver();
    cout << "La parte real de a es " << a.getr() << endl;
    cout << "La parte imaginaria de a es " << a.geti() << endl;
    c.ver();
    cout << "La parte real de c es " << c.getr() << endl;
    cout << "La parte imaginaria de c es " << c.geti() << endl;
    cout << "------------\n";
    a.ver();
    b.ver();
    a=a+b; a.ver();
    a=a+2; a.ver();
    a=3+a; a.ver();

    a=b+c; a.ver();
    a=c+b; a.ver();
    a=c+2; a.ver();
    a=3+c; a.ver();

    a=-b; a.ver(); b.ver();
    a=-c; a.ver(); c.ver();
    return 0;
}
