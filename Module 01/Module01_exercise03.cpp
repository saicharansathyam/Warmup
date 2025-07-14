#include <iostream>
#include <vector>

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
    vector<VehicleComponent*> components;

public :
    void addComponent (VehicleComponent* component){
        components.push_back(component);
    }

    void runAllComponents(){
        for (VehicleComponent* comp : components) {
            comp->performFunction();

        }
    }
    ~SoftwareDefinedVehicle() {
        for (VehicleComponent* comp : components) {
            delete comp;

        }
    }
};

int main()
{
    SoftwareDefinedVehicle myCar;

    EngineControl* engine = new EngineControl();
    engine ->setRPM(2500);

    InfotainmentSystem* infotainment = new InfotainmentSystem();
    infotainment ->playMedia("Time in a bottle");

    myCar.addComponent(engine);
    myCar.addComponent(infotainment);

    myCar.runAllComponents();


    return 0;
}
