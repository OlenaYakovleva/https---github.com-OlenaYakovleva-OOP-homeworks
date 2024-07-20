// Используя класc Fraction, представленный ниже, добавьте перегрузку операторов << и >>. Следующий фрагмент кода:
#include <iostream>
using namespace std;

class Fraction
{
private:
    int uper;
    int downer;

public:
    Fraction(int uper = 0, int downer = 1) // default constructor, denominator can not be 0!!!
    {
        this->uper = uper;
        this->downer = downer;
    }
    // showing method
    void print()
    {
        cout << uper << "/" << downer << endl;
    }
    friend Fraction operator*(const Fraction &f1, const Fraction &f2);
    friend istream &operator>>(istream &cin, Fraction &f);
    friend ostream &operator<<(ostream &cout, const Fraction &f);
};

// Перегрузка оператора *
Fraction operator*(const Fraction &f1, const Fraction &f2)
{
    return Fraction(f1.uper * f2.uper, f1.downer * f2.downer);
}

// Перегрузка оператора ввода
istream &operator>>(istream &cin, Fraction &f)
{
    char slash;
    cin >> f.uper >> slash >> f.downer;
    return cin;
}
// Перегрузка оператора <<
ostream &operator<<(ostream &cout, const Fraction &f)
{
    cout << f.uper << "/" << f.downer;
    return cout;
}

int main()
{
    Fraction f1;
    cout << "Enter fraction 1: ";
    cin >> f1;
    f1.print();

    Fraction f2;
    cout << "Enter fraction 2: ";
    cin >> f2;
    f2.print();

    cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';

    return 0;
}
