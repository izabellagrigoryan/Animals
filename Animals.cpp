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
public:

    Lion(int weight)
    {
        this->weight = weight;
        this->classname = "  " + this->classname + typeid(*this).name() + "  ";
        
        Animal::count++;
    }

    Lion(Lion&& animal)
    {
        if (this != &animal)
        {
            this->weight = animal.weight;
            this->classname = animal.classname;
            animal.weight = 0;
            animal.classname = "";
            std::cout << "This is move constructor" << std::endl;
        }
    }

    Lion& operator=(Lion&& animal) noexcept
    {
        if (this != &animal)
        {
            this->weight = animal.weight;
            this->classname = animal.classname;
            animal.weight = 0;
            animal.classname = "";
            std::cout << "This is move assignment" << std::endl;
        }
        return *this;
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

};

int Animal::count = 0;

int main()
{
    Lion lion1(500);
    Lion lion2(800);

    if (lion1 < lion2)
        std::cout << "The weight of the Lion1 less than the weight of the Lion2" << std::endl;

    if (lion1 > lion2)
        std::cout << "The weight of the Lion1 more than the weight of the Lion2" << std::endl;

    if (lion1 == lion2)
        std::cout << "The weight of the Lion1 is equal to the weight of the Lion2" << std::endl;
    
    lion1();
    
    std::cout << "Count of the created Lions = " << Animal::count << std::endl << std::endl;
    
    Animal::direction dir = lion1.convert_to_int("right");
    string str = lion1.convert_to_string(Animal::direction::right);

    Lion lion3 = Lion(1000);
    std::cout << lion3.weight << std::endl;
    Lion lion4(std::move(lion3));

    lion3 = std::move(lion2);
    std::cout << lion3.weight << "  " << lion2.weight << std::endl;

    return 0;
}
