#include <iostream>
#include <memory>
#include <vector>

class Shape {
public:
    Shape() { std::cout << "Shape created.\n"; }
    virtual ~Shape() { std::cout << "Shape destroyed.\n"; }
    virtual void render() const {
        std::cout << "Rendering generic shape.\n";
    }
};

class ComplexPolygon : public Shape {
    std::vector<double> vertexArray;
    int vertexCount;
public:
    explicit ComplexPolygon(int count)
        : vertexArray(static_cast<std::size_t>(count) * 2), vertexCount(count) {
        std::cout << "Allocated " << vertexCount << " vertices on heap.\n";
    }
    ~ComplexPolygon() override {
        std::cout << "Deallocating polygon vertex heap memory.\n";
    }
    void render() const override {
        std::cout << "Rendering polygon with " << vertexCount << " vertices.\n";
    }
};

int main() {
    std::unique_ptr<Shape> shapePtr = std::make_unique<ComplexPolygon>(1000);
    shapePtr->render();
}
