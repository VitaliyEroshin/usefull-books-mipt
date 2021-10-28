#include <iostream>

struct A {
  int x;
  int y;
  int z;
};

struct B {
  int a;
};

int main() {
  B b;
  B *pb = &b;
  A *pa = (A *)pb;
  // A *pa = static_cast<A *>(pb);
  // A *pa = reinterpret_cast<A *>(pb);
  std::cout << pz->z << std::endl;
}
