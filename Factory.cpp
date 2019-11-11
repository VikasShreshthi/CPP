/* Factory Design Pattern Example */

#include <iostream>
using namespace std;
/* shape is library and its implementation is hidden to client */
enum shapeType
{
    st_square, st_circle, st_line
};

class shape
{
    public:
    virtual inline void draw() = 0;
    static shape* createShape(shapeType type);
};

class square:public shape
{
    public:
    inline void draw()
    {
        cout<<"square::draw()"<<endl;
    }
};

class circle:public shape
{
    public:
    inline void draw()
    {
        cout<<"circle::draw()"<<endl;
    }
};

class line:public shape
{
    public:
    inline void draw()
    {
        cout<<"line::draw()"<<endl;
    }
};

// factory method to create and return differnt shape's
shape* shape::createShape(shapeType type)
{
    if (type == st_square)
    {
        return new square();
    }
    else if (type ==  st_circle)
    {
        return new circle();
    }
    else if (type == st_line)
    {
        return new line();
    }
    else
    {
        return NULL;
    }
}

/* -------------------------------------------------------------*/
// Client code



class client
{
    shape* pShape;
    public:
        client(shapeType t)
        {
            pShape = shape::createShape(t);
        }
        ~client()
        {
            delete[] pShape;
            pShape=NULL;
        }
        inline shape* getShape(){return pShape;}
};

int main ()
{
    // as we are passing line it will create obj for line.
    client* pc = new client(st_line);
    pc->getShape()->draw();
    client* pc1 = new client(st_circle);
    pc1->getShape()->draw();
    client* pc2 = new client(st_square);
    pc2->getShape()->draw();
    return 0;
}

// Going ahead if lib adds new shape then client code need not be recompiled.