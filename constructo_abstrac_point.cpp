// Створіть клас, що представляє точку в тривимірному просторі. Клас має містити
// конструктор для ініціалізації координат точки та деструктор для виведення повідомлення про знищення об'єкта.

#include <iostream>
using namespace std;

class Point3D {
    double a, b, c;
    public:
    //constructor and initialisation of cordinates
    Point3D (double x, double y, double z): a(x), b(y), c(z) {
        cout<<"Points are created: "<<x<<", "<<y<<", "<<z<<endl;
    };

    //destructor
    ~Point3D() {
        cout << "Point (" << a << ", " << b << ", " << c << ") destroyed" << endl;
    }
};

int main()
{
    //3 objects of the class Point3D are:
    Point3D p1(1,4,5);
    Point3D p2(3,6,8);
    Point3D p3(6,9,1);
    return 0; //they are destroyed here after main is done
}





