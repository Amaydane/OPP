#include <iostream>
#include"OrdinaryFraction.h"

using namespace std;

int main()
{
    OrdinaryFraction a;
    a.setNumDen("2/5");
    OrdinaryFraction b("3/7");
    OrdinaryFraction t = a * b;
    OrdinaryFraction d = a + b;
    OrdinaryFraction c = a / b;
    OrdinaryFraction e = a - b;
    t.getNumDen();
    cout << "\n";
    d.getNumDen();
    cout << "\n";
    c.getNumDen();
    cout << "\n";
    e.getNumDen();
    cout << "\n";
    double x = d.translateToDecimal();
    cout << x << "\n";
    return 0;
}
