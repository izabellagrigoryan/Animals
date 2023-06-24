// Animals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class Animal
{
private:
    const string name = "It's an Animal";
public:
    Animal()
    {
        cout << this->name << endl;
    }
    ~Animal()
    {
        cout << "Really it was an Animal" << endl;
    }
};

class Mammal : public Animal
{
private:
    const string name = "It's a Mammal";
public:
    Mammal():Animal()
    {
        cout << this->name << endl;
    }

    ~Mammal()
    {
        cout << "Really it was a Mammal" << endl;
    }
};

class Lion : public Mammal
{
private:
    const string name;
public:
    Lion(string name): name(name) , Mammal()
    {
        cout << this->name << endl;
    }

    ~Lion()
    {
        cout << "Really it was a Lion" << endl;
    }
};

int main()
{
    Lion lion("It isn't Elephant");

    return 0;
}

