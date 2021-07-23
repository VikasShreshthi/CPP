// Create your own smart pointer
#include<iostream>
using namespace std;	

class SPTR
{
	int* ptr;
	public:
	explicit SPTR(int* p)
	{
		cout<<"created "<<p<<endl;
		ptr = p;
		*ptr=0;
	}
	~SPTR()
	{
		cout<<"deleted "<<ptr<<endl;
		delete ptr;
	}
	int& operator*(){return *ptr;}
};

int main()
{
	SPTR sp(new int());
	cout<<"*sp"<<*sp<<endl;
	*sp = 77;
	cout<<"*sp"<<*sp<<endl;
	return 0;
}