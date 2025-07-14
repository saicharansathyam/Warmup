#include <iostream>
using namespace std;

// Base class
class Car {
protected:
    string make;
    string model;
    int year;

public:
    // Constructor
    Car(const string& mk, const string& mdl, int yr) {
        make = mk;
        model = mdl;
        year = yr;
        cout << "Car constructor called\n";
    }

    // Drive function
    void drive() {
        cout << "Driving " << make << " " << model << " (" << year << " edition)" << endl;
    }
};

// Derived class
class SportsCar : public Car {
private:
    int topSpeed;

public:
    // Constructor
    SportsCar(const string& mk, const string& mdl, int yr, int speed)
        : Car(mk, mdl, yr), topSpeed(speed) {
        cout << "SportsCar constructor called\n";
    }

    // Overridden drive function
    void drive() {
        Car::drive(); // Call base class drive
        cout << "Top speed: " << topSpeed << " km/h" << endl;
    }
};

// Main function
int main() {
    cout << "\n=== Creating Sports Car ===\n";
    SportsCar sc("Ferrari", "488 GTB", 2020, 330);

    cout << "\n=== Driving Sports Car ===\n";
    sc.drive();

    return 0;
}
