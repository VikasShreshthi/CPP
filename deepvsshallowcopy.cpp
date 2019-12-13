#include <iostream>
#include<cstring> 
using namespace std;

class mystr
{
    int len;
    char* data;
    public:
    mystr(const char* p)
    {
        len = strlen(p);
        data = new char[len+1];
        strcpy( data, p);
    }
    void change(const char* p)
    {
        delete[] data;
        len = strlen(p);
        data = new char[len+1];
        strcpy( data, p);
    }
    /*mystr(const mystr& src)
    {
        len = src.len;
        data = new char[len+1];
        strcpy(data, src.data);
    }
    
    mystr& operator =(const mystr& src)
    {
        len = src.len;
        data = new char[len+1];
        strcpy(data, src.data);
        return *this;
    }*/
    
    void showdata()
    {
        cout<<"info:"<<data<<endl;
    }
};

int main ()
{
  mystr x("Abc");
  x.showdata();
  mystr y=x;
  y.showdata();
  mystr z("pqr");
  z = x;
  z.showdata();
  /* if we comment assignment and copyconstructor then its example of shallow copy  in that case all x, y and z object points to same data memory location*/
  cout<<"-------------------------------"<<endl;
  x.change("www");
  x.showdata();
  y.showdata();
  z.showdata();
  
  return 0;
}
