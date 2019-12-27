#include <string>
#include <iostream>
using namespace std;
int main()
{
    string text = "This, is sample, test application, 123";
    string d = ",";
    size_t begin = text.find_first_not_of (d); 
    size_t end = text.find_first_of(d, begin);
    cout<<" begin: "<<begin<<" end: "<<end<<" d: "<<d<<endl;
    cout<<" str: "<<text.substr(begin,end - begin)<<endl;

    begin = text.find_first_not_of (d, end+1); 
    end = text.find_first_of(d, end+1);
    cout<<" begin: "<<begin<<" end: "<<end<<" d: "<<d<<endl;
    cout<<" str: "<<text.substr(begin,end - begin)<<endl;


    begin = text.find_first_not_of (d, end+1); 
    end = text.find_first_of(d, end+1);
    cout<<" begin: "<<begin<<" end: "<<end<<" d: "<<d<<endl;
    cout<<" str: "<<text.substr(begin,end - begin)<<endl;

    begin = text.find_first_not_of (d, end+1); 
    end = text.find_first_of(d, end+1);
    cout<<" begin: "<<begin<<" end: "<<end<<" d: "<<d<<endl;
    cout<<" str: "<<text.substr(begin,end - begin)<<endl;
    return 0;
}