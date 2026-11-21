#include <cstring>
#include <iostream>
#include <utility>

class DynamicString {
    std::size_t length;
    char* buffer;
public:
    explicit DynamicString(const char* text) : length(std::strlen(text)), buffer(new char[length + 1]) {
        std::memcpy(buffer, text, length + 1);
    }
    DynamicString(const DynamicString& other) : length(other.length), buffer(new char[length + 1]) {
        std::memcpy(buffer, other.buffer, length + 1);
    }
    DynamicString& operator=(const DynamicString& other) {
        if (this != &other) {
            char* replacement = new char[other.length + 1];
            std::memcpy(replacement, other.buffer, other.length + 1);
            delete[] buffer;
            buffer = replacement;
            length = other.length;
        }
        return *this;
    }
    ~DynamicString() { delete[] buffer; }
    void print() const { std::cout << buffer << '\n'; }
};
int main() {
    DynamicString s1("Antigravity C++");
    DynamicString s2 = s1;
    s2.print();
}
