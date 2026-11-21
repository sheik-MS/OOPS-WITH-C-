#include <iostream>
class Vehicle {public:int maxSpeed;explicit Vehicle(int s):maxSpeed(s){} virtual ~Vehicle()=default;virtual void honk()const{std::cout<<"General Horn\n";}};
class SportsCar:public Vehicle {public:bool turboEnabled;SportsCar(int s,bool t):Vehicle(s),turboEnabled(t){} void engageTurbo()const{std::cout<<"Turbo Engaged!\n";}};
int main(){Vehicle* vPtr=new SportsCar(300,true);vPtr->honk();if(auto* sports=dynamic_cast<SportsCar*>(vPtr))sports->engageTurbo();SportsCar car(250,true);Vehicle& vehicleRef=car;std::cout<<"Referenced speed: "<<vehicleRef.maxSpeed<<"\n";std::cout<<"Turbo enabled: "<<std::boolalpha<<car.turboEnabled<<"\n";delete vPtr;}
