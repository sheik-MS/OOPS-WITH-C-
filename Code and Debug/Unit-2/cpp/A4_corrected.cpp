#include <iostream>
#include <string>
class Student {
    int rollNumber;
    std::string name;
public:
    Student() : rollNumber(0), name("") {}
    Student(int r, std::string n) : rollNumber(r), name(n) {}
    void display() const {
        std::cout << "Roll: " << rollNumber << ", Name: " << name << '\n';
    }
};
int main() {
    Student batch[3];
    batch[0] = Student(101, "Aarav");
    batch[1] = Student(102, "Bhavna");
    batch[2] = Student(103, "Chirag");
    for (int i = 0; i < 3; ++i) batch[i].display();
}
