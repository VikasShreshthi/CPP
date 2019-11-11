#include <iostream>

using namespace std;
// signgle ton example
class fruit
{
  int seeds;
  static fruit *obj;
    fruit (int s)
  {
    seeds = s;
  }
  fruit (fruit& temp){

     }
public:
    inline int getVal ()
  {
    return seeds;
  }
  inline void setVal (int x)
  {
    seeds = x;
  }
  static fruit *getInstance ()
  {
    if (!obj)
      obj = new fruit (10);
    return obj;
  }
};

fruit *
  fruit::obj = nullptr;

int
main ()
{
  cout << "fruit demo: " << fruit::getInstance ()->getVal ();
  //fruit   x (fruit::getInstance ());
  return 0;
}
