#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal {
  public:
    Animal() {
      cout << "Animal::Animal()" << endl;
    }
    Animal(string name): name(name) {
      cout << "Animal::Animal" << name << ")" << endl;
    }

    virtual ~Animal() {
      cout << "Animal::~Animal" << this->name << ")" << endl;
    }

    virtual void print() {
      cout << "Animal: " << name << endl;
    }
  protected:
    string name;
};

class Mammal : public Animal {
  public:
    Mammal() {
      cout << "Mammal::Mammal" << endl;
    }

    ~Mammal() {
      cout << "Mammal::~Mammal(" << this->name << ")" << endl;
    }

    Mammal(string name) : Animal(name) {}

    void print() {
      cout << "MAMMAL! -> " << this->name << endl;
    }
};

int main() {
  // Animal a1("snail");
  // a1.print();
  //
  // Mammal m1("tiger");
  // m1.print();

  vector<Animal*> zoo;
  zoo.push_back(new Mammal("bird"));
  zoo.push_back(new Animal("fish"));

  for (auto *a : zoo) {
    a->print();
  }

  for (size_t i=0; i<zoo.size(); i++) {
    delete zoo[i];
  }
  zoo.clear();

  return 0;
}
