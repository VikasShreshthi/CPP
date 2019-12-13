#include<iostream>
#include<thread>

using namespace std;

void foo(int xyz)
{
    cout<<"thread create using function pointer ("<<xyz<<")"<<endl;
}

// A callable object 
class thread_obj { 
public: 
    thread_obj()
    {
        cout << "thread_obj()"<<endl;
    }
    thread_obj(const thread_obj & x)
    {
        cout << "CP thread_obj()"<<endl;
    }
    void operator()(int x) 
    { 
        for (int i = 0; i < x; i++) 
            cout << "Thread using function"
                  " object as  callable "<<i<<endl; 
    }
    ~thread_obj()
    {
        cout << "~ thread_obj()"<<endl;
    }
}; 

int main()
{
auto fun = [] (int z){cout<<"thread created using functor"<<endl;};
//thread th1(foo, 122);
//thread th2(fun, 445);
thread th3(thread_obj(),2);
//th1.join();
//th2.join();
th3.join();    
//thread_obj();
}