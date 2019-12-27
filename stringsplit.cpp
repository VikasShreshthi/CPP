/*You want to split a delimited string into multiple strings. For example, you may
want to split the string "Name|Address|Phone" into three separate strings, "Name",
"Address", and "Phone", with the delimiter removed.*/

#include <string>
#include <vector>
#include <functional>
#include <iostream>
using namespace std;

void strsplit ( const string& s, char c, vector<string>& v )
{
	string::size_type i = 0;
	string::size_type j = s.find(c);
	while (j!=string::npos)
	{
		v.push_back(s.substr(i,j-i));
		i = ++j;
		j = s.find(c,j);

		if (j!=string::npos)
		{
			//v.push_back(s.substr(i,s.length()));
		}
	}
    v.push_back(s.substr(i,s.length()));
}

int main()
{
	vector<string> v;
	//string s = "Name|Age|City|Company";
    string s = "Name,Age,City,Company";
    char c = ',';
	strsplit(s,c,v);
	/*for (int i = 0; i<v.size(); i++)
	{
		cout<<v[i]<<endl;
	}*/
    for (auto x : v)
        cout<<x<<endl;
}