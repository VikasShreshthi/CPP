#include <iostream>

using namespace std;

class A
{
    public:
    virtual void show()
    {cout<<"A show"<<endl;}
};

class C
{
    public:
    virtual void fun()
    {cout<<"c fun"<<endl;}
};


class B : public A, public C
{
    public:
    void show()
    {cout<<"B show"<<endl;}
    
    void fun()
    {cout<<"B fun"<<endl;}
};

int main ()
{
  B* obj = new B();
  cout<<"size "<<sizeof(obj)<<endl;
  obj->fun();
  obj->show();
  return 0;
}
