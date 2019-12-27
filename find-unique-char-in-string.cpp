/*
Below prog will find unique char in given string.
 */
#include <vector>
#include <string>
#include <set>
#include <iostream>
using namespace std;

int main()
{
string str = "Lets do it";
set<char> s;
for (auto c: str)
{
  s.insert(c);
}
cout<<"number of unique char in given string : "<<s.size()<<endl;
return 0;
}
