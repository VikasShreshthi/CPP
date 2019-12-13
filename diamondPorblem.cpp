#include <iostream>

using namespace std;
class A
{
    public :
    int x;
    //virtual void show();
};

class B:virtual public A
{
    public :
    int y;
    //void show();
};

class C:virtual public A
{
    public :
    int z;
    //void show();
};

class D:public B,public C
{
    public :
    int xyz;
};


int
main ()
{
  A obja;
  /* code compiles until we wont access x from objd. when we access x from objd compilor gives error as it wont be able to resolve ambiguty */
  cout<<sizeof(obja)<<endl;

  B objb;
  cout<<sizeof(objb)<<endl;
  
  C objc;
  cout<<sizeof(objc)<<endl;
  
  D objd;
  cout<<sizeof(objd)<<endl;
  
  return 0;
}
