// Створіть клас `Array`, який представляє масив цілих чисел. Додайте дружню функцію, яка приймає два об'єкти класу `Array` як параметри та створює новий масив, який містить суму елементів відповідних позицій цих двох масивів.

#include <iostream>
#include <ctime>
using namespace std;

class Array {
private:
    int* ms;
    int size;

public:
    Array(int size2) : size(size2) {
        ms = new int[size]; //new memory
        for (int i = 0; i < size; i++) {
            ms[i] = rand() % 45;
        }
        cout << "Public: Array created\n";
    }
    void display() const {
        for (int i = 0; i < size; i++)
        {
            cout<< ms[i] <<" "<<endl;
        }
        cout <<"Display func in -public- just worked"<<endl;
        cout << endl;
    }

    ~Array() {
        delete[] ms;
    }

    friend Array sumArray(const Array& a, const Array& b);
};

Array sumArray(const Array& a, const Array& b) { 
    Array result(a.size); // a size = b size
    for (int i = 0; i < a.size; i++) {
        result.ms[i] = a.ms[i] + b.ms[i];
    }
    cout << "Friend: SumArray - just worked\n";
    cout << endl;
    return result;
}

int main() {
    srand(static_cast<unsigned int>(time(NULL))); 
    
    cout << "Array a:\n";
    Array a(5);
    a.display();

    cout << "Array b:\n";
    Array b(5);
    b.display();

    Array result = sumArray(a, b);
    cout << "Sum of arrays:\n";
    result.display();

    return 0;
}

