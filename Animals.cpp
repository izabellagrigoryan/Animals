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

    static int count;

    Animal()
    {
        this->classname = typeid(*this).name() + string("  ");
    }
    
    virtual ~Animal() {}
};

class Mammal : public Animal
{
public:
    Mammal()
    {
        this->classname = "  " + this->classname + typeid(*this).name() + "  ";
    }
    
    ~Mammal() {}
};

class Lion : public Mammal
{
private:

    Lion(int weight)
    {
        this->weight = weight;
        this->classname = "  " + this->classname + typeid(*this).name() + "  ";
        
        Animal::count++;
    }

public:

    static Lion* create_lion(int weight)
    {
         if (Animal::count < 1)
         {
             Lion* ptr = new Lion(weight);
             return ptr;
         }
         std::cout << "You can't create more than one lion" << std::endl;
         return NULL;
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

    Lion& operator++()
    {
        Animal::count++;
        
        return *this;
    }

    Lion operator++(int)
    {
        Lion temp = *this;
        ++*this;
        return temp;
    }

    Animal& operator()()
    {
        cout << this->classname << endl;
        return *this;
    }

};

int Animal::count = 0;

int main()
{
    Lion* lion1 = Lion::create_lion(500);
    Lion* lion2 = Lion::create_lion(800);

    if (lion1 && lion2)
    {
        if (lion1 < lion2)
            std::cout << "The weight of the Lion1 less than the weight of the Lion2" << std::endl;

        if (lion1 > lion2)
            std::cout << "The weight of the Lion1 more than the weight of the Lion2" << std::endl;

        if (lion1 == lion2)
            std::cout << "The weight of the Lion1 is equal to the weight of the Lion2" << std::endl;

        //lion1();
    }
    std::cout << "Count of the created Lions = " << Animal::count << std::endl << std::endl;
    
    Lion c1 = ++*lion1;
    Lion c2 = (*lion1)++;

    std::cout << Animal::count << endl;

    return 0;
}
