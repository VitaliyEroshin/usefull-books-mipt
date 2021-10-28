#include <iostream>

struct T {
  T() : a(1), b(1) {};
  int a;
  int b;
};

int main() {
  T *ptr = static_cast<T, *>(malloc(sizeof(T) * 100));
  // T *ptr = new T[100];
  std::cout << ptr[50].a << ' ' << ptr[50].b << std::endl;
  free[ptr];
  // delete[] ptr;
}
