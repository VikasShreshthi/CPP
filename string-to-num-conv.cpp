#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

int main()
{
	string number = "123456";
	char* p;
	cout<<"string :"<<number<<endl;
	cout<<"num : "<<strtol(number.c_str(),&p, 0);
}

