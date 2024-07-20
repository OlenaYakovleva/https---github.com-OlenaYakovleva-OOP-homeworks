#include <iostream>
using namespace std;

class ElectronicDevice {
protected:
    string model;
    int yearManufacture;
    double price;

public:
    ElectronicDevice(string model, int yearManufacture, double price) {
        this->model = model;
        this->yearManufacture = yearManufacture;
        this->price = price;
    }

    void printInfo() {
        cout << "Model: " << model << endl;
        cout << "Year of manufacture: " << yearManufacture << endl;
        cout << "Price: $" << price << endl;
    }
};

class Phone : public ElectronicDevice {
private:
    int screenSize;
    string operatingSystem;

public:
    Phone(string model, int yearManufacture, double price, int screenSize, string operatingSystem)
        : ElectronicDevice(model, yearManufacture, price) {
        this->screenSize = screenSize;
        this->operatingSystem = operatingSystem;
    }

    void printPhoneInfo() {
        printInfo();
        cout << "Screen size: " << screenSize << " inches" << endl;
        cout << "Operating system: " << operatingSystem << endl;
    }
};

class Tablet : public ElectronicDevice {
private:
    int screenSize;
    int batteryLife;
   
public:
    Tablet(string model, int yearManufacture, double price, int screenSize, int batteryLife)
        : ElectronicDevice(model, yearManufacture, price) {
        this->screenSize = screenSize;
        this->batteryLife = batteryLife;
        
    }

    void printTabletInfo() {
        printInfo();
        cout << "Screen size: " << screenSize << " inches" << endl;
        cout << "Battery life: " << batteryLife << " hours" << endl;
    
    }
};

class Laptop : public ElectronicDevice {
private:
    string processor;
    int RAM;

public:
    Laptop(string model, int yearManufacture, double price, string processor, int RAM)
        : ElectronicDevice(model, yearManufacture, price) {
        this->processor = processor;
        this->RAM = RAM;
    }

    void printLaptopInfo() {
        printInfo();
        cout << "Processor: " << processor << endl;
        cout << "RAM: " << RAM << " GB" << endl;
    }
};

int main() {
    // Eksemplary klasiv
    Phone iPhone("iPhone 12", 2020, 999.99, 6, "iOS");
    Tablet Samsung("Samsung Galaxy Tab S6", 2020, 599.99, 10, 10);
    Laptop Dell("Dell XPS 15", 2020, 1999.99, "Intel Core i7", 16);

    // info about electro devices
    iPhone.printPhoneInfo();
    cout << endl;
    Samsung.printTabletInfo();
    cout << endl;
    Dell.printLaptopInfo();
    return 0;
}
