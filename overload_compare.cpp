// Реалізуйте клас Date, що представляє дату, з можливістю перевантаження логічних операторів для порівняння дат.
//  Клас Date повинен мати приватні поля:
// день (int day`);
// місяць (int month`);
// рік (int year`).
//  -Конструктор класу повинен приймати три параметри: день, місяць та рік.
// - Перевантажте наступні логічні оператори для класу `Date:
// ==для порівняння двох дат на рівність.
// != для перевірки нерівності двох дат.
// >для порівняння двох дат (чи одна дата менша за іншу).
// <для порівняння двох дат (чи одна дата більша за іншу).
//<= для порівняння двох дат (чи одна дата менша або рівна іншій).
// >= для порівняння двох дат (чи одна дата більша або рівна іншій).
// -Додайте метод для виведення дати у рматі "день. місяць.рік".
#include <iostream>
using namespace std;
class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
    // перевантаження логічних операторів
    bool operator==(const Date &other) const
    {
        return (day == other.day && month == other.month && year == other.year);
    }

    bool operator!=(const Date &other) const
    {
        bool result = !(*this == other);
        return result;
    }
    bool operator<(const Date &other) const
    { // checking years
        if (year < other.year)
        {
            return true;
        }
        else if (year > other.year)
        {
            return false;
        }

        // Если года равны, сравниваем месяцы
        if (month < other.month)
        {
            return true;
        }
        else if (month > other.month)
        {
            return false;
        }

        // Если и месяцы равны, сравниваем дни
        if (day < other.day)
        {
            return true;
        }
        else
        {
            return false; // Если и дни равны или текущий день больше
        }
    }

    bool operator>(const Date &other) const
    {
        // Проверяет, больше ли текущая дата по сравнению с other
        return !(*this < other) && !(*this == other);
    }
    bool operator>=(const Date &other) const
    {
        bool result = !(*this < other);
        return result;
    }
    bool operator<=(const Date &other) const
    {
        return *this < other || *this == other;
    }
    void printDate() const
    {
        cout << day << "." << month << "." << year << endl;
    }
};
int main()
{
    Date d1(21, 10, 2024);
    Date d2(25, 12, 2022);
    cout << boolalpha;
    cout << "d1 == d2: " << (d1 == d2) << endl;
    cout << "d1!= d2: " << (d1 != d2) << endl;
    cout << "d1 < d2: " << (d1 < d2) << endl;
    cout << "d1 > d2: " << (d1 > d2) << endl;
    cout << "d1 <= d2: " << (d1 <= d2) << endl;
    cout << "d1 >= d2: " << (d1 >= d2) << endl;
    d1.printDate();
    d2.printDate();
    return 0;
}
