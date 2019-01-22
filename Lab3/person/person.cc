#include <iostream>

struct Person {
  std::string name;
  int age;
};

void PrintPerson(struct Person *p) {
  std::cout << p->name << " is " << p->age << " years old.\n";
}

int main() {
  Person p;

  p.name = "John";
  p.age = 10;

  PrintPerson(&p);
  return 0;
}
