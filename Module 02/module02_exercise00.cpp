#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

class VehicleComponent {
public :
    virtual void performFunction () = 0;
    virtual ~VehicleComponent(){

    }
};

class EngineControl : public VehicleComponent {
private :
    int rpm = 0;
public :
    void setRPM(int value){
        rpm = value;
    }
    int getRPM() const {
        return rpm;
    }
    void performFunction() override {
        cout << "Engine is running at " << rpm << " RPM." <<endl;
    }
};

class InfotainmentSystem : public VehicleComponent {
private:
    string currentMedia;
public:
    void playMedia (const string& media){
        currentMedia = media;
    }

    void performFunction() override {
        cout << "Playing Media : " << currentMedia << endl;
    }
};

class SoftwareDefinedVehicle {
private :
    vector<unique_ptr<VehicleComponent>> components;

public :
    void addComponent(unique_ptr<VehicleComponent> component){
        components.push_back(std::move(component));
    }

    void runAllComponents(){
        for (const auto& comp : components) {
            comp->performFunction();

        }
    }

};

int main()
{
    SoftwareDefinedVehicle myCar;

    auto engine = make_unique<EngineControl>();
    engine ->setRPM(2500);

    auto infotainment = make_unique<InfotainmentSystem>();
    infotainment ->playMedia("Time in a bottle");

    myCar.addComponent(std::move(engine));
    myCar.addComponent(std::move(infotainment));

    myCar.runAllComponents();


    return 0;
}
