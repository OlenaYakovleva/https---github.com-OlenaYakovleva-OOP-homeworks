#include <iostream>
#include <ctime>
using namespace std;

class Resource
{
private:
    int *data;   // pointer to dynamic massive
    size_t size; // size of massive

public:
    // Constructor default
    Resource(size_t size) : size(size)
    {
        data = new int[size]; // create massive
    }

    // Copy constructor
    Resource(const Resource &obj) : size(obj.size)
    {
        data = new int[size]; // create new massive
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = obj.data[i];
        } // copy elements
    }

    // Move constructor
    // Конструктор перемещения
    Resource(Resource &&obj) : data(obj.data), size(obj.size)
    {
        obj.data = nullptr; // обнуляем указатель у исходного объекта предотвратить двойное освобождение памяти.
        obj.size = 0;       // обнуляем размер у исходного объекта
    }

    // Destructor
    ~Resource()
    {
        if (data != nullptr)
        {
            delete[] data;
            cout << "destructor was called now!" << endl;
        }
        else
        {
            cout << "empty" << endl;
        }
    }

    // Method to fill the massive with random values
    void fillRandom()
    {
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = rand() % 45; // fill with random values from 0 to 44
        }
    }

    // Method to print the content of the massive
    void print() const
    {
        for (size_t i = 0; i < size; ++i)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    srand(time(0));

    Resource r1(10);
    r1.fillRandom(); // fill the massive with random values
    cout << "Resource 1: ";
    r1.print();

    Resource r2(r1); //  Resource 2 as a copy of Resource 1
    cout << "Resource 2 (copy of Resource 1): ";
    r2.print();

    Resource r3(std::move(r1)); // 1 is moved to 3, and its data = 0 now.
    cout << "Resource 3: 1 moved to 3 and emptied data : ";
    r1.print();

    return 0;
}