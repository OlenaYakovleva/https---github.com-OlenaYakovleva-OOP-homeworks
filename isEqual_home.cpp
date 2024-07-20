
//  Добавьте функцию isEqual() в класс Numbers, чтобы следующий код работал корректно:
#include <iostream>
using namespace std;

class Numbers {
    private:
    double x, y, z;

    public:
    void setValues(double a, double b, double c) {
        x = a;
        y = b;
        z = c;
    }
    bool isEqual(Numbers num) {
        return (x == num.x && y == num.y && z == num.z);
    }
};

int main()
{
Numbers point1;
point1.setValues(3.0, 4.0, 5.0);

Numbers point2;
point2.setValues(3.0, 4.0, 5.0);

if (point1.isEqual(point2))
    cout << "point1 and point2 are equal\n";
else 
    cout << "point1 and point2 are not equal\n";

Numbers point3;
point3.setValues(7.0, 8.0, 9.0);

if (point1.isEqual(point3))
    cout << "point1 and point3 are equal\n";
else 
    cout << "point1 and point3 are not equal\n";
return 0;
}
