#include <iostream>
#include <string>

class Stack {
  int size = 0;

  struct Node {
    int value;
    Node* previous;
  };

  Node* head = nullptr;

  public:
    void push(int x) {
      Node* node = new Node();
      node->previous = head;
      node->value = x;
      head = node;
      size++;
    }

    void print_back() {
      if (head == nullptr)
        std::cout << "error\n";
      else
        std::cout << head->value << '\n';
    }

    void pop() {
      print_back();
      if (head == nullptr)
        return;

      Node* new_head = head->previous;
      delete head;
      head = new_head;
      size--;
    }

    void clear() {
      Node* new_head;
      while (head != nullptr) {
        new_head = head->previous;
        delete head;
        head = new_head;
      }
      size = 0;
    }

    void print_size() {
      std::cout << size << '\n';
    }
};

int main() {
  #ifdef local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  Stack s;

  std::string q;
  std::cin >> q;
  
  while (q != "exit") {
    if (q == "push") {
      int x;
      std::cin >> x;
      s.push(x);
      std::cout << "ok\n";
    }

    if (q == "pop") {
      s.pop();
    }

    if (q == "back") {
      s.print_back();
    }
      
    if (q == "size") {
      s.print_size();
    }
      
    if (q == "clear") {
      s.clear();
      std::cout << "ok\n";
    }

    std::cin >> q;
  }
  s.clear();
  std::cout << "bye";
}