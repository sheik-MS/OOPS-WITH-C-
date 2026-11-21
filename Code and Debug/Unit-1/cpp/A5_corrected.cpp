#include <iostream>
int main() {
    const int size = 5;
    int *readings = new int[size];
    for (int i = 0; i < size; ++i) {
        readings[i] = (i + 1) * 10;
    }
    int total = 0;
    for (int i = 0; i < size; ++i) {
        total += readings[i];
    }
    std::cout << "Total: " << total << '\n';
    delete[] readings;
    return 0;
}
