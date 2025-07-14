#include <iostream>

using namespace std;

class Car{
private :
    string name;
    int speed;

public :
// Default constructor
    Car() {
        name = "Unknown";
        speed = 100;

    }

 // Paramterised constructor
    Car(const string& n, int s){
        name = n;
        speed = s;
    }
// Copy constructor
    Car(const Car& other){
        name = other.name;
        speed = other.speed;
    }
// Copy operating constructor
    Car& operator=(const Car& other){
        name = other.name;
        speed = other.speed;
        return *this;
    }

// Destructor - cleans up when car is destroyed
        ~Car() {
        cout << "Destructor: " << name << " is being destroyed! Goodbye!" << endl;
    }


    void display() {
        cout << "Car " << name << " and speed is " << speed << "km/h\n";
    }

};

int main()
{
    cout << "\n=== Creating Cars ===" << endl;
    Car car1;
    car1.display();
    Car car2 ("VW", 200);
    car2.display();


    cout << "\n=== Making a copy ===" << endl;
    Car car3 = car2;
    car3.display();

    cout << "\n=== Assignment ===" << endl;
    Car car4(car1);
    car4.display();

    cout << "\n=== Program ending - cars being destroyed ===" << endl;

    return 0;
}
