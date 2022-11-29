#Created by Melnykov Dmytro
#include <iostream>
#include <math.h>

using namespace std;

class Puck
{
    float a,s;
public:

    void SetA(float a)
    {
        this->a = a;
    }


    Puck()
    {
        SetA(0);
    }

    Puck(float a)
    {
        SetA(a);
    }

    ~Puck()
    {

    }

    float GetA()
    {
        return a;
    }

    float Area()
    {
        this->a = a;
        float s = ((3*sqrt(3))/2)*a*a;
        return s;
    }

    friend ostream& operator << (ostream& os, Puck& obj);
    friend Puck operator + (Puck obj1, Puck obj2);

};

//перевантаження оператора виведення
ostream& operator << (ostream& os, Puck& obj)
{
    return os << " Довжина сторони = " << obj.a << "\n Площа = " << obj.Area() << endl;
}

//перевантаження оператора додавання
Puck operator + (Puck obj1, Puck obj2)
{
    Puck obj3;
    obj3.s = obj1.Area()+ obj2.Area();
    obj3.a = sqrt(2.0 / 3.0 * obj3.s / sqrt(3.0));
    return obj3;
}

int main()
{
    system("CHCP 65001");
    float a;
    cout << "Введiть першу довжину сторони a = ";
    cin >> a;
    Puck Puck_1 = Puck(a);
    cout << "Перший об'єкт " << Puck_1;
    cout << "Введiть другу довжину сторони a = ";
    cin >> a;
    Puck Puck_2 = Puck(a);
    cout << "Другий об'єкт " << Puck_2;
    Puck Puck_3;
    Puck_3 = Puck_1 + Puck_2;
    cout<<"Фінальна шайба - "<<Puck_3;
}
