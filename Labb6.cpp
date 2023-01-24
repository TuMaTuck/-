//created by Melnykov Dmytro
// іграшка, продукт, товар, молочний продукт;
#include <iostream>
#include <string>

using namespace std;

class Product
{
protected:
    string maker;
public:

    Product(string mk)
    {
        this->maker=mk;
    }
    void setMaker(string mk)
    {
        maker=mk;
    }
    string getMaker()
    {
        return maker;
    }
    ~Product()
    {
    }
};

class Ware : public Product
{
protected:
    int cod;
    int kilkist;
    int prs;
public:
    Ware(int num, int sum, int num1,string mk) : Product(mk)
    {
        this->cod=num;
        this->prs=sum;
        this->kilkist=num1;
    }
    void setCod(int num)
    {
       cod=num;
    }
    int getCod()
    {
        return cod;
    }

    void setPRS(int sum)
    {
        prs=sum;
    }
    int getPRS()
    {
        return prs;
    };


    void setKilkist(int num1)
    {
        kilkist=num1;
    }
    int getKilkist()
    {
        return kilkist;
    }
    ~Ware()
    {
    }
};


class MlkPr:public Ware
{
protected:
    string nameMil;
public:
    MlkPr(int num, string tow, int sum, int num1, string mk): Ware (num,sum,num1,mk)
    {
        this->nameMil=tow;
    }

    void setNameMiklPr(string tow)
    {
        nameMil=tow;

    }
    string getNameMiklPr()
    {
        return nameMil;
    }

    ~MlkPr()
    {
    }

    void ShowRez1()
    {
        cout<<"Код товару - "<< cod <<" Назва молочного продукту - "<< nameMil << " Ціна товару = " << prs << "грн" <<endl;
        cout<<"Кількість товару - "<< kilkist << " Виробник товару - " << maker <<endl;
    }

};

class Toy : public Ware
{
protected:
    string nop;
public:
    Toy(int num, string tow, int sum, int num1,string mk) : Ware (num,sum,num1,mk)
    {
        this->nop=tow;
    }

    void setNameOfToy(string tow)
    {
        nop=tow;
    }
    string getNameOfProd()
    {
        return nop;
    }

    void ShowRez2()
    {
        cout<<"Код товару - "<< cod <<" Назва іграшки - "<< nop << " Ціна товару = " << prs << "грн" <<endl;
        cout<<"Кількість товару - "<< kilkist << " Виробник товару - " << maker <<endl;
    }

    ~Toy()
    {
    }
};



int main()
{
    system("CHCP 65001");

    MlkPr second(21,"Сир",70,321,"ТДВ Яготинський маслозавод");
    cout<<"\n"<<endl;
    second.ShowRez1();

    Toy first(123,"Лялька",300, 212,"ТОВ Пластик");
    cout<<"\n"<<endl;
    first.ShowRez2();

    return 0;
}
