//Create by Melnykov Dmytro
#include <iostream>

using namespace std;

class Engine
{
public:
    virtual void GetStats() = 0;
};

class ELKTengine : public Engine
{
    int power;
    int HighV;
    int phase;
public:
    ELKTengine(int p, int h, int ph)
    {
        this->power=p;
        this->HighV=h;
        this->phase=ph;
    }

    void GetStats() override
    {
        cout<< "Електричний двигун має Потужність - " << power << " квт; Напругу - " << HighV << " В; Фази - " << phase <<endl;
    }
    ~ELKTengine()
    {
    }
};

class INCOMengine : public Engine
{
    int obdv;
    int power;
    int fuel;
public:
    INCOMengine(int p, int o, int fl)
    {
        this->power=p;
        this->obdv=o;
        this->fuel=fl;
    }

    void GetStats() override
    {
        cout<< "Паливний двигун має Потужність - " << power << " к.с; Об'єм двигуна - " << obdv << " л; Витрачає - " << fuel << " на 100 км" <<endl;
    }
    ~INCOMengine()
    {
    }
};

class Perpetuum : public Engine
{
    int obdv;
    int power;
    int fuel;
public:
    Perpetuum(int p, int o, int fl)
    {
        this->power=p;
        this->obdv=o;
        this->fuel=fl;
    }

    void GetStats() override
    {
        cout<< "Вічний двигун має Потужність - " << power << " к.с; Об'єм двигуна - " << obdv << " л; Витрачає - " << fuel << " на 100 км" <<endl;
    }
    ~Perpetuum()
    {
    }
};


int main()
{
    system("CHCP 65001");
    Engine *A[3];
    ELKTengine elk(8000,500, 12);
    INCOMengine inco(220,3,7);
    Perpetuum per(1,2,10000);
    cout<<"\n"<<endl;
    A[0]=&elk;
    A[1]=&inco;
    A[2]=&per;
    for(int i = 0; i < 3; i++)
    {
        A[i]->GetStats();
    }

    return 0;
}
