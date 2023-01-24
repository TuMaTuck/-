//created by Melnykov Dmytro
//Клас - одновимірний масив. Додатково перевантижити наступні операції:
// << вивід на консоль
// + - об'єднати два масиви

#include <iostream>
using namespace std;

const int SIZE = 8;

template <class AType>
class atype{
public:
  AType a[SIZE];
  atype()
  {

    for (int i = 0; i < SIZE; i++) {
      a[i] = (rand() % 90 + 10) / 5;
    }
  }
  template <class t> friend void operator + (atype<AType>& var1, atype<AType>& var2);
};

template <class AType>
void operator + (atype<AType>& var1, atype<AType>& var2)
{
  int j = 0;
  AType sum[SIZE + SIZE] = { 0 };
  cout<<"[";
    for (int i = 0; i < SIZE; i++)
    {
      sum[i] = var1.a[i];
      cout<<sum[i]<<" ";
    }
    cout<<"]"<<endl<<"[";
    for (int i = SIZE; i < SIZE + SIZE; i++)
    {
      sum[i] = var2.a[j];
      cout<<sum[i]<<" ";
      j++;
    }
    cout<<"]"<<endl;
    cout << "Масив (Масив 1  + Масив 2)" << endl;
    cout<<"[";
    for (int i = 0; i < SIZE  + SIZE; i++)
        {
            cout << sum[i] << " ";
        }
    cout<<"]"<<endl;

}

template <class AType>
ostream& operator<<(ostream& t, atype<AType>& A)
{
  for (int i = 0; i < SIZE; i++)
  {
      t << A.a[i] << " ";
      t << endl;
      return t;
  }


}

int main()
{
  system("CHCP 65001");

  atype<int> obj1 ,obj2;
  cout << "Масив 1 ";
  cout << obj1;
  cout << "Масив 2 ";
  cout << obj2;
  obj1 + obj2;
  return 0;
}
