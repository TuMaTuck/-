//Created by Melnykov Dmytro
#include <iostream>
#include <locale.h>
#include <math.h>

using namespace std;

class puck
{
private:
	float s, a;
public:
	puck();
	puck(float);
	~puck();
	float print_sqrt();
};

puck::puck() //конструктор
{
	a = 0;
	cout << "Початок розрахунку\n" << endl;
}

puck::puck(float a) //конструктор
{
	this->a = a;
}

float puck::print_sqrt()
{

	s = ((3 * (sqrt(3))) / 2) * pow(a, 2);

	cout << "Довжина сторони даної шайби - " << a << "см\n" << "Площа даної фiгури " << s << "см^2\n" << endl;

	return s;
}


puck::~puck() //деконструктор
{
	cout << "Розрахунок завершено" << endl;
}


int main()
{
	setlocale(0, "UKRAINIAN");

	puck area;
	puck area2(10.0);

	area.print_sqrt();

	area2.print_sqrt();

	return 0;
}
