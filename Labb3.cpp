#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    string surname;
    string name;
    int physics;
    int math;
    int it;

public:
    void Set(string surname, string name, int physics, int math, int it)
    {
        this->surname = surname;
        this->name = name;
        this->physics = physics;
        this->math = math;
        this->it = it;
    }
    string GetSurName()
    {
        return surname;
    }

    string GetName() 
    { 
      return name; 
    }
    int Getphysics() 
    { 
      return physics; 
    }
    int Getmath() 
    { 
      return math; 
    }
    int Getit() 
    { 
      return it; 
    }


    void Print() 
{

        cout << surname << " " << name
             << "   Marks: Physics= " << physics << " Math = " << math<< " It = " << it << endl;
    }
};

int main() {
    int kilkist = 0;
    int n;
    string str;
    ifstream fin("data.txt");
    if (fin)
    {
        while (!fin.eof())
        {
            getline(fin, str, '\n');
            kilkist++;
        }

        Student *P = new Student[kilkist];
        fin.clear();
        fin.seekg(0);
        for (int i = 0; i < kilkist; i++)
        {
            string sname;
            string nname;
            int a, b, c;
            fin >> sname;
            fin >> nname;
            fin >> a;
            fin >> b;
            fin >> c;
            P[i].Set(sname, nname, a, b, c);
        }
        for (int i = 0; i < kilkist - 1; i++)
        {
            for (int j = i + 1; j < kilkist; j++)
            {
                if (P[i].GetSurName() > P[j].GetSurName())
                {
                    swap(P[i], P[j]);
                }
            }
        }

        cout << "Information about students:" << endl;
        for (int i = 0; i < kilkist; i++)
        {
            P[i].Print();
        }
        cout<<"\nInput the mark of physics - ";
        cin>>n;
        cout << "All students with " << n << " mark";

        for (int i = 0; i < kilkist; i++)
            if (P[i].Getphysics() == n)
            {
                P[i].Print();
            }
        fin.close();
        delete[] P;
    } else
        cout << "File not found"<< endl;
}
