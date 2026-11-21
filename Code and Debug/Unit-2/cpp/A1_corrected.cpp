#include <iostream>
int getMaximumScaled(int a, int b, int scaleFactor) {
    int maxVal = (a > b) ? a : b;
    return maxVal * scaleFactor;
}
int& getArrayElement(int arr[], int index) { return arr[index]; }
int main() {
    int x = 10, y = 20;
    int scaledMax = getMaximumScaled(x, y, 2);
    std::cout << "Scaled Max: " << scaledMax << '\n';
    int data[3] = {100, 200, 300};
    getArrayElement(data, 1) = 999;
    std::cout << "Updated Array[1]: " << data[1] << '\n';
    std::cout << "Stored Scaled Max: " << scaledMax << '\n';
}
