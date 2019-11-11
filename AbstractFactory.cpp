/* Abstract Factory Design Pattern Example */

#include <iostream>
using namespace std;

class request
{
    public:
    virtual void show()=0;
};

class usbReq:public request
{
    public:
        inline void show(){cout<<"usbReq "<<endl;}
};

class btReq:public request
{
    public:
        inline void show(){cout<<"btReq "<<endl;}
};

class response
{
    public:
    virtual void show()=0;
};

class usbRes:public response
{
    public:
        inline void show(){cout<<"usbRes "<<endl;}
};

class btRes:public response
{
    public:
        inline void show(){cout<<"btRes "<<endl;}
};

class createReqRespFactory
{
    public:
    virtual request* createReq() = 0;
    virtual response* createRes() =0;
};

class usbFactory:public createReqRespFactory
{
    public:
    request* createReq()
    {
        return new usbReq();
    }
    response* createRes()
    {
        return new usbRes();
    }
};

class btFactory:public createReqRespFactory
{
    public:
    request* createReq()
    {
        return new btReq();
    }
    response* createRes()
    {
        return new btRes();
    }
};


int main ()
{
    createReqRespFactory* obj = new btFactory();
    obj->createReq()->show();
    obj->createRes()->show();

    obj = new usbFactory();
    obj->createReq()->show();
    obj->createRes()->show();

    return 0;
}

// Going ahead if lib adds new shape then client code need not be recompiled.