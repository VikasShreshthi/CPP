#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main()
{
	int x = 90;
	float f = 34.65;
	stringstream ss,ss1;
	ss<<x;
	string sx = ss.str();
	cout<<"x: "<<sx<<endl;
	//ss.flush();
	ss1<<f;
	string sf = ss1.str();
	cout<<"f: "<<sf<<endl;
}
