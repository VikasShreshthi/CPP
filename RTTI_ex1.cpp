//#include <cassert>
#include <typeinfo>
#include <iostream>
using namespace std;
class X {
 int i;
public:
// If virtual function is added then only *xp will show runtime object created else complile time
virtual void abc()=0;
 // ...
};
class Y : public X {
 int j;
public:
void abc(){}
 // ...
};
int main() {
    X* xp = new Y;
    // If vptr there then shows Y else shows X
    cout<<"x: "<<typeid(*xp).name()<<endl;
    cout<<"X: "<<typeid(X).name()<<endl;
    cout<<"Y: "<<typeid(Y).name()<<endl;
 } ///:~