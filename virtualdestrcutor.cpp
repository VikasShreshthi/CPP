#include <iostream>
using namespace std;
/*
struct Shape
{
    ~Shape() { cout << "Shape dtor\n"; }
};

struct Circle : public Shape
{
    ~Circle() { cout << "Circle dtor\n"; }
};

int main()
{
    Shape *i = new Circle;
    delete i;
}
*/
// Output of above will be 
// Shape dtor 
// With this we can see that dtor of base class called beacuse pointer is of type base class that is Shape. In this destrcution of derived object is incomplete.


// Lets solve above problem by adding virtual destructor in base class that is Shape
struct Shape
{
    virtual ~Shape() { cout << "Shape dtor\n"; }
};

struct Circle : public Shape
{
    ~Circle() { cout << "Circle dtor\n"; }
};

int main()
{
    Shape *i = new Circle;
    delete i;
}
