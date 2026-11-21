#include <iostream>

class Entity {
public:
    virtual ~Entity() = default;
    virtual void attack() const {
        std::cout << "Entity performs generic scratch.\n";
    }
};

class Dragon : public Entity {
public:
    void attack() const override {
        std::cout << "Dragon breathes scorching fire!\n";
    }
};

void triggerEncounter(const Entity& e) {
    e.attack();
}

int main() {
    Dragon boss;
    triggerEncounter(boss);
}
