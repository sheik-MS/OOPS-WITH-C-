#include <iostream>
class StepCounter {
    int steps;
public:
    explicit StepCounter(int s = 0) : steps(s) {}
    StepCounter& operator++() { ++steps; return *this; }
    StepCounter operator++(int) { StepCounter old = *this; ++steps; return old; }
    void display(const char* label) const { std::cout << label << ": " << steps << '\n'; }
};
int main() {
    StepCounter c1(10);
    StepCounter c2 = ++c1;
    c2.display("Prefix snapshot c2");
    c1.display("After prefix c1");
    StepCounter c3 = c1++;
    c3.display("Postfix snapshot c3");
    c1.display("After postfix c1");
    ++(++c1);
    c1.display("After chained prefix c1");
}
