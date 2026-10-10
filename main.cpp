#include <iostream>
#include "Queue.h"


using namespace std;

int main(){
    Q a, b,c;

    a.push(1);
    a.push(2);
    a.push(3);
    b << 10 << 20 << 30;

    cout << a << endl;
    cout << b << endl;

    cout << (a + b) << endl;
    Q  d = a;
    d += b;
    cout << d << endl;
    cout << (a < b ) << endl;
    return 0;
}
