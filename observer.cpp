#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Observer design pattern
// https://medium.com/@gayashanbc/explore-the-observer-design-pattern-with-c-8592459b0486

// Observer useally have subject and observer interfaces.
// Subject has registerObserver, removeObserver and notify methods.<which needs to be defined by dervied classes>
// observer has update method. <which needs to be defined by dervied classes>.
// We will have GPSReciver <subclass of subject> class as subject which will send update to its clients <subclass of observer>.

class observer
{
    public:
        virtual void update(int lat, int lon) = 0;
};

class subject
{
    public:
        virtual void registerObserver(observer* p) = 0;
        virtual void unregisterObserver(observer* p) = 0;
        virtual void notify() = 0;
};

class GPSReciver:public subject
{
    vector<observer*> clients;
    int lat,lon;
    public:
    void registerObserver(observer* p) override 
    {
        clients.push_back(p);
    }
    void unregisterObserver(observer* p) override
    {
        auto it = std::find(clients.begin(), clients.end(), p);
        if (it!=clients.end())
            clients.erase(it);
    }
    void notify() override
    {
        for(observer* client:clients)
            client->update(lat,lon);
    }
    inline void setData(int x, int y)
    {
        lat = x;
        lon = y;
        notify();
    }
};

class client:public observer
{
    int id;
    public:
    void update(int lat, int lon) override
    {
        cout<<"Client"<<id<<" update lat "<<lat<<" lon "<<lon<<endl;
    }
    client(int p):id(p)
    {
    }
};

int main ()
{
  client hmi(1);
  client app1(2);
  GPSReciver gpsRx;
  gpsRx.registerObserver(&hmi);
  gpsRx.registerObserver(&app1);
  cout<<"-----------------------------------"<<endl;
  gpsRx.setData(58,45);
  cout<<"-----------------------------------"<<endl;
  gpsRx.setData(78,45);
  cout<<"-----------------------------------"<<endl;
  gpsRx.unregisterObserver(&app1);
  gpsRx.setData(98,45);
  cout<<"-----------------------------------"<<endl;
  gpsRx.unregisterObserver(&hmi);
  gpsRx.setData(118,45);
  cout<<"-----------------------------------"<<endl;
  return 0;
}
