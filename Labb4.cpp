//Created by Melnykov Dmytro 
#include <iostream>

using namespace std;

class ElOfArr
{
private:
    int size;
    int* Array;
public:
    ElOfArr(int size)
    {
        cout << "\nКонструктор " << this << " викликаний" << endl;
        this->size = size;
        this->Array = new int[size];
        for (int i = 0; i < size; i++)
        {
            if (i % 2 == 0)
            {
                Array[i] = i - 2;
            }
            else
            {
                Array[i] = i + 5;
            }
        }
        for (int i = 0; i < size; i++)
        {
            cout << Array[i] << "   ";
        }

    }

    ElOfArr(const ElOfArr& other)
    {
        int sum = 0;
        this->size = other.size;
        this->Array = new int[other.size];//покажчик на масив
        for (int i = 0; i < other.size; i++)
        {
            this->Array[i] = other.Array[i];
        }
        for (int i = 0; i < other.size; i++)
        {
            if (this->Array[i] % 2 != 0)
            {
                sum+=Array[i];
            }
        }
        cout << "\nСума непарних елементiв = " << sum << endl;
        cout << "\nКонструктор копiювання " << this << " викликаний" << endl;
    }
    
    ~ElOfArr()
    {
        cout << "Деструктор " << this << " викликаний" << endl;
        delete[] Array;
    }
};

void OddEl(const ElOfArr& first)
{
    ElOfArr second(first);
}

int main()
{
    system("CHCP 65001");
    ElOfArr first(9);
    OddEl(first);
    return 0;
}
