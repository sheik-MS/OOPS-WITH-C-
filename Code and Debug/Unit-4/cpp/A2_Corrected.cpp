#include <iostream>
#include <string>
class Device {protected: std::string macAddress; public: explicit Device(std::string mac):macAddress(mac){std::cout<<"Device configured with MAC: "<<macAddress<<'\n';}};
class Sensor:public Device {int samplingRate; public: Sensor(std::string mac,int rate):Device(mac),samplingRate(rate){} void display()const{std::cout<<"MAC: "<<macAddress<<", Rate: "<<samplingRate<<" Hz\n";}};
int main(){Sensor tempSensor("00:1A:2B:3C:4D:5E",100);tempSensor.display();}
