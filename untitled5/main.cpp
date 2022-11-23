#define CATCH_CONFIG_RUNNER

#include <iostream>
#include <cstring>
#include "Array.h"
#include "library.h"
#include "method.h"

using namespace std;

int main() {
    Array a(10);
    //Matrix z(3);
    //z.setMatrix(1, 0, 5);
    //z.setMatrix(0, 0, 1);
   // z.setMatrix(1, 1, 50);    //cout<<k.getMatrix(1, 1)<<endl;
    //Matrix b(z);
    RectangularMatrix t(3,4);
    t.setMatrix(0,0,10);
    cout<<t.toString()<<endl;
    //cout << b.toString() << endl;
    // a.deleteArray(2);
    //cout<<a.get(2)<<endl;
   // z.setMatrix(1, 0, 5);
    //cout<<a.getArrayPart(2, 5)<<endl;
    //cout<<a.Count<<endl;
    //a.existArray(14);
    //cout<<k.getMatrix(1, 0)<<endl;
    //cout<<l.getMatrix(1,1)<<endl;
    //cout << b.Gauss(3,4) <<endl;
    //cout<<c.getMatrix(0, 2)<<endl;

    //cout<<t.getMatrix(1,0)<<endl
}