// Напишіть програму на C++, яка демонструє застосування множинного спадкування. Створіть два базових класи `Person` та Worker`. Клас `Person` повинен мати метод `getName()`, який повертає ім'я людини, а клас Worker - метод 'getJobTitle()`, який повертає назву роботи. Створіть похідний клас `Employee`, який успадковує обидва базові класи і має метод *getEmployeeInfo()`, який повертає інформацію про працівника (ім'я та назва роботи).
#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string name;

public:
    Person(string Name) : name(Name) {}
    string getName() { return name; }
};
class Worker
{
private:
    string jobTitle;

public:
    Worker(string jobTitle)
    {
        this->jobTitle = jobTitle;
    }
    string getJobTitle() { return jobTitle; }
};

class Employee : public Person, public Worker
{
public:
    Employee(string Name, string jobTitle) : Person(Name), Worker(jobTitle) {}
    void getEmployeeInfo() {
        cout << "Name: " << getName() << endl;
        cout << "Job Title: " << getJobTitle() << endl;
    }
};

int main()
{
    Employee emp ("Edward Smith", "Doctor");
    emp.getEmployeeInfo();
    return 0;
}
