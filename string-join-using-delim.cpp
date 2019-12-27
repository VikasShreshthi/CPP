/* joining strings into one string by adding delimiter char
This can be used if we have directory list without /
ex:
input strings: C,Test,ABCD
Output string : C/Test/ABCD
 */
#include <vector>
#include <string>
#include <iostream>
using namespace std;
/*
int main()
{
vector<string> inputStr;
string out;
string delim = "/";

inputStr.push_back("C:");
inputStr.push_back("Test");
inputStr.push_back("ABC");
inputStr.push_back("Finalwarn");

for (auto ipst = inputStr.begin(); ipst != inputStr.end(); ipst++)
{
  out+=*ipst;
  if (ipst != inputStr.end()-1)
      out+=delim;
}

cout<<out<<endl;

return 0;
}
*/

// We will convert above code in func
void joindelim(vector<string>& s, string& d, string& o)
{

for (auto ipst = s.begin(); ipst != s.end(); ipst++)
{
  o+=*ipst;
  if (ipst != s.end()-1)
      o+=d;
}

}

int main()
{
vector<string> inputStr;
string out;
string delim = "/";

inputStr.push_back("C:");
inputStr.push_back("Test");
inputStr.push_back("ABC");
inputStr.push_back("Finalwarn");

joindelim(inputStr,delim,out);
cout<<out<<endl;
}
