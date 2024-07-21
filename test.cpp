#include <iostream>
using namespace std;

class A
{

public:
    int value = 0;
};

// Базовий клас
class Animal : public A
{
public:
    void speak()
    {
        std::cout << "speak Animal" << std::endl;
    }
};

// Ще один базовий клас
class Bird : public A
{
public:
    void chirp()
    {
        std::cout << "chirp bird" << std::endl;
    }
};

// Клас, який успадковує від обох базових класів
class Parrot : public Animal, public Bird
{
public:
    void mimic()
    {
        std::cout << "mimic parrot" << std::endl;
    }
};

int main()
{
    Parrot parrot;

    // parrot.speak();  // Викликає метод з базового класу Animal
    // parrot.chirp();  // Викликає метод з базового класу Bird
    // parrot.mimic();  // Викликає метод класу Parrot

    parrot.value = 10;
    // std::cout << parrot.value << std::endl;

    // parrot.value = 6;
    // std::cout << parrot.value << std::endl;

    std::cout << parrot.Animal::value << std::endl;
    std::cout << parrot.Bird::value << std::endl;

    return 0;
}