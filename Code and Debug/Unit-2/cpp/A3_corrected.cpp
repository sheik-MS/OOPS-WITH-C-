#include <iostream>
double cuboidVolume(double length, double width = 1.0, double height = 1.0) {
    return length * width * height;
}
double cubeVolume(double side) { return side * side * side; }
double cylinderVolume(double radius, double height) {
    return 3.14159 * radius * radius * height;
}
int main() {
    std::cout << "Volume: " << cubeVolume(5.0) << '\n';
    std::cout << "Cylinder: " << cylinderVolume(3.0, 7.0) << '\n';
    std::cout << "Cuboid: " << cuboidVolume(5.0, 2.0, 3.0) << '\n';
}
