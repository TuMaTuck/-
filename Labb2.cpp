//created by Melnykov Dmytro
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <locale.h>

using namespace std;

class Krest
{
private:
    double a, b;
public:


    Krest()
    {
        SetA(0);
        SetB(0);
    }

    Krest(double valueA, double valueB)
    {
        SetA(valueA);
        SetB(valueB);
    }

    ~Krest()
    {

    }

    double GetA()
    {
        return a;
    }

    double GetB()
    {
        return b;
    }

    void SetA(double valueA)
    {
        a = valueA;
    }

    void SetB(double valueB)
    {
        b = valueB;
    }

    double GetAreaOfKrest()
    {
        double S = ((pow(b,2))+(4*a*b));
        return S;
    }

    void Print_sqrt()
    {
        cout << "Площа хреста зi сторонами " << GetA() << " та " << GetB() << " = " << GetAreaOfKrest() << endl;
    }

    //підключення дружньої функції
    friend Krest SumArea(Krest& first, Krest& second);
};

//дружня функція, яка виконує потрібні для задачі обчислення
Krest SumArea(Krest& first, Krest& second)
{
    double a = first.GetA() + second.GetA();
    double b = first.GetB() + second.GetB();
    Krest newKrest(a,b);
    return newKrest;
}


int main()
{
    setlocale(0,"UKRAINIAN");

    Krest firstKrest(11, 3);
    Krest secondKrest(14, 7);


    firstKrest.Print_sqrt();
    secondKrest.Print_sqrt();


    Krest thirdKrest = SumArea(firstKrest, secondKrest);

    thirdKrest.Print_sqrt();
}
