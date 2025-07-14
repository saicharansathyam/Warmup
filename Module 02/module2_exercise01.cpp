#include <iostream>
#include <memory>
#include <vector>
using namespace std;

// Base Part class - Foundation for all car components
class Part {
public:
    virtual void print() = 0;  // Pure virtual function
    virtual void operate() = 0; // Additional behavior for parts
    virtual ~Part() = default;  // Virtual destructor for proper cleanup
};

// Engine class - Heart of the Range Rover
class Engine : public Part {
private:
    string type;
    double displacement;
    int horsepower;

public:
    Engine(string engineType = "V8 Supercharged", double disp = 5.0, int hp = 518)
        : type(engineType), displacement(disp), horsepower(hp) {}

    void print() override {
        cout << "Range Rover Engine: " << type << endl;
        cout << "  Displacement: " << displacement << "L" << endl;
        cout << "  Horsepower: " << horsepower << " HP" << endl;
    }

    void operate() override {
        cout << "Engine roaring with " << horsepower << " HP of power!" << endl;
    }

    void startEngine() {
        cout << "Range Rover engine started - Ready for adventure!" << endl;
    }
};

// Wheel class - Off-road capability
class Wheel : public Part {
private:
    int size;
    string tireType;

public:
    Wheel(int wheelSize = 22, string tire = "All-Terrain")
        : size(wheelSize), tireType(tire) {}

    void print() override {
        cout << "Range Rover Wheel: " << size << "\" with " << tireType << " tires" << endl;
    }

    void operate() override {
        cout << "Wheels gripping terrain with " << tireType << " tires" << endl;
    }

    void adjustPressure() {
        cout << "Adjusting tire pressure for optimal off-road performance" << endl;
    }
};

// Brake class - Advanced braking system
class Brake : public Part {
private:
    string brakeType;
    bool absEnabled;

public:
    Brake(string type = "Ventilated Disc", bool abs = true)
        : brakeType(type), absEnabled(abs) {}

    void print() override {
        cout << "Range Rover Brake: " << brakeType;
        if (absEnabled) cout << " with ABS";
        cout << endl;
    }

    void operate() override {
        cout << "Brakes engaging with " << brakeType << " system" << endl;
        if (absEnabled) cout << "ABS preventing wheel lockup" << endl;
    }

    void emergencyBrake() {
        cout << "Emergency braking activated - Maximum stopping power!" << endl;
    }
};

// Transmission class - Smooth power delivery
class Transmission : public Part {
private:
    string transmissionType;
    int gears;

public:
    Transmission(string type = "8-Speed Automatic", int numGears = 8)
        : transmissionType(type), gears(numGears) {}

    void print() override {
        cout << "Range Rover Transmission: " << transmissionType << endl;
        cout << "  Gears: " << gears << endl;
    }

    void operate() override {
        cout << "Transmission smoothly shifting through " << gears << " gears" << endl;
    }

    void selectTerrainMode() {
        cout << "Transmission adapting to terrain - Optimizing gear ratios" << endl;
    }
};

// Car class - Complete Range Rover model
class Car {
private:
    unique_ptr<Engine> engine_;
    vector<unique_ptr<Wheel>> wheels_;
    vector<unique_ptr<Brake>> brakes_;
    unique_ptr<Transmission> transmission_;
    string model_;
    string color_;

public:
    Car(string model = "Range Rover Sport", string color = "Santorini Black")
        : model_(model), color_(color) {

        // Initialize engine with smart pointer
        engine_ = make_unique<Engine>();

        // Initialize 4 wheels
        for (int i = 0; i < 4; ++i) {
            wheels_.push_back(make_unique<Wheel>());
        }

        // Initialize 4 brakes (one per wheel)
        for (int i = 0; i < 4; ++i) {
            brakes_.push_back(make_unique<Brake>());
        }

        // Initialize transmission
        transmission_ = make_unique<Transmission>();
    }

    void printCarDetails() {
        cout << "\n=== " << model_ << " (" << color_ << ") ===" << endl;
        cout << "A luxury SUV built for both city streets and rugged terrain\n" << endl;

        // Print all parts
        engine_->print();
        cout << endl;

        cout << "Wheels & Tires:" << endl;
        wheels_[0]->print();  // All wheels are identical, so print one
        cout << endl;

        cout << "Braking System:" << endl;
        brakes_[0]->print();  // All brakes are identical, so print one
        cout << endl;

        transmission_->print();
        cout << endl;
    }

    void startJourney() {
        cout << "=== Starting Range Rover Journey ===" << endl;
        engine_->startEngine();
        transmission_->selectTerrainMode();

        cout << "\nAll systems operational:" << endl;
        engine_->operate();
        transmission_->operate();
        wheels_[0]->operate();

        cout << "\nRange Rover ready for any adventure!" << endl;
    }

    void offRoadMode() {
        cout << "\n=== Engaging Off-Road Mode ===" << endl;
        for (auto& wheel : wheels_) {
            wheel->adjustPressure();
        }
        transmission_->selectTerrainMode();
        cout << "Range Rover configured for off-road excellence!" << endl;
    }

    void emergencyStop() {
        cout << "\n=== Emergency Stop ===" << endl;
        for (auto& brake : brakes_) {
            brake->emergencyBrake();
        }
    }

    // Destructor automatically handles cleanup with smart pointers
    ~Car() {
        cout << "\nRange Rover safely parked - Journey complete!" << endl;
    }
};

int main() {
    cout << "Welcome to the Range Rover Experience!" << endl;

    // Create a Range Rover
    Car myRangeRover("Range Rover Evoque", "Fuji White");

    // Display car details
    myRangeRover.printCarDetails();

    // Start the journey
    myRangeRover.startJourney();

    // Demonstrate off-road capabilities
    myRangeRover.offRoadMode();

    // Demonstrate emergency braking
    myRangeRover.emergencyStop();

    return 0;
}
