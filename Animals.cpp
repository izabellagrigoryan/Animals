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

    enum class direction {
        left,
        right,
        forward,
        back,
    };
    
    direction convert_to_int(std::string st)
    {       
        if (st == "left")
            return direction::left;
        else if (st == "right")
            return direction::right;
        else if (st == "forward")
            return direction::forward;
        else if (st == "back")
            return direction::back;

        return direction::left;
     
    }

    string convert_to_string(direction dir)
    {
        if (dir == direction::left)
            return "left";
        else if (dir == direction::right)
            return "right";
        else if (dir == direction::forward)
            return "forward";
        else if (dir == direction::back)
            return "back";

        return "Unknown";
    }

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

    Animal::direction dir = lion1->convert_to_int("right");
    string str = lion1->convert_to_string(Animal::direction::right);
   
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
