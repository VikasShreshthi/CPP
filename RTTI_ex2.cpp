/*//#include <cassert>
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
 } ///:~          */


 #include <cassert>
#include <typeinfo>
#include <iostream>
using namespace std;

class D1 {
public:
 virtual void func() {}
 virtual ~D1() {}
};
class D2 {
public:
 virtual void bar() {}
};
class MI : public D1, public D2 {};
class Mi2 : public MI {};
int main() {
 D2* d2 = new Mi2;
 Mi2* mi2 = dynamic_cast<Mi2*>(d2);
 MI* mi = dynamic_cast<MI*>(d2);
 D1* d1 = dynamic_cast<D1*>(d2);

    cout<<"*d2: "<<typeid(*d2).name()<<endl;
    cout<<"Mi2*: "<<typeid(Mi2*).name()<<endl;
    cout<<"*d2: "<<typeid(*d2).name()<<endl;
    cout<<"D2*: "<<typeid(D2*).name()<<endl;

// assert(typeid(d2) != typeid(Mi2*));
 //assert(typeid(d2) == typeid(D2*));
} ///:~