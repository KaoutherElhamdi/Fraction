#include "Fraction.h"
#include <iostream>

using namespace std;

int main()
{
    Fraction a(4,5),b(2),c,d, e;         //Déclare deux fractions valant 0

    c = a+b;               //Calcule 4/5 + 2/1 = 14/5

    d = a*b;               //Calcule 4/5 * 2/1 = 8/5

    e = a-b;

    cout << a << " + " << b << " = " << c << endl;

    cout << a << " * " << b << " = " << d << endl;

    cout << a << " - " << b << " = " << e << endl;

    if(a > b)
        cout << "a est plus grand que b." << endl;
    else if(a==b)
        cout << "a est egal a b." << endl;
    else
        cout << "a est plus petit que b." << endl;

    Fraction f(5,8), p(2,3), k(4,-8);

    cout << "(" << p << ") ^ 2 = " << pow(p, 2) << endl;

    cout << k << endl;
    cout << "valeur absolue de " << k << " = " << abs(k) << endl;

    cout << " 2.5 = " << reelToFraction(2.5) << endl;

    Fraction ff(f);
    if (f==ff)
        cout << " f = ff" << endl;
    else
        cout << " f # ff" << endl;

    cout << a << " = " << a.nombreReel() << endl;

    return 0;
}
