// Animals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <typeinfo>

using namespace std;
class Animal
{ 
public:
    int weight;
    string classname;

    Animal()
    {
        this->classname = typeid(*this).name() + string("  ");
    }

    bool operator<(const Animal& animal)
    {
        if (this->weight < animal.weight)
            return true;
        else
            return false;
    }
    bool operator>(const Animal& animal)
    {
        if (this->weight > animal.weight)
            return true;
        else
            return false;
    }
    bool operator==(const Animal& animal)
    {
        if (this->weight == animal.weight)
            return true;
        else
            return false;
    }

    Animal& operator()()
    { 
        cout << this->classname << endl;
        return *this;
    }

    virtual ~Animal(){}    
};

class Mammal : public Animal
{
public:   
    Mammal()
    {
        this->classname = "  " + this->classname + typeid(*this).name() + "  ";
    }
    ~Mammal(){}   
};

class Lion : public Mammal
{
public:   
    Lion(int weight)
    {
        this->weight = weight;
        this->classname = "  " + this->classname + typeid(*this).name() + "  ";
    }
    
    ~Lion(){}    
};

int main()
{
    Lion lion1(500);
    Lion lion2(700);
    //Animal* lion1 = new Lion(900);
    //Animal* lion2 = new Lion(500);

    if(lion1 < lion2) 
        std::cout << "The weight of the Lion1 less than the weight of the Lion2" << std::endl;
    
    if(lion1 > lion2)
        std::cout << "The weight of the Lion1 more than the weight of the Lion2" << std::endl;

    if(lion1 == lion2)
        std::cout << "The weight of the Lion1 is equal to the weight of the Lion2" << std::endl;

    lion1();

    return 0;
}

