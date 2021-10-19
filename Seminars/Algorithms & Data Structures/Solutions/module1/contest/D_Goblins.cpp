#include <iostream>

class GucciQueue {
  int size = 0;

  struct Node {
    int value;
    Node* left;
    Node* right;
  };

  Node* tail = nullptr;
  Node* mid = nullptr;
  Node* head = nullptr;

  void setup(Node* node) {
    tail = node;
    mid = node;
    head = node;
  }

  void rebalance() {
    if (size % 2) {
      Node* node_mid = mid->right;
      mid = node_mid;
    }
  }
  
  public:
    void push_back(int x) {
      size++;

      Node* node = new Node();
      node->value = x;

      if (size == 1) {
        setup(node);
      }
      
      node->left = tail;
      tail->right = node;
      tail = node;

      rebalance();
    }


    void push_mid(int x) {
      size++;

      Node* node = new Node();
      node->value = x;

      if (size == 1) {
        setup(node);
        return;
      }

      if (size == 2) {
        tail = node;
        head->right = node;
        return;
      }

      node->right = mid->right;
      node->left = mid;
      mid->right->left = node;
      mid->right = node;

      rebalance();
    }

    int front() {
      return head->value;
    }

    int pop() {
      int res = head->value;
      size--;
      rebalance();
      Node* new_head = head->right;
      delete head;
      head = new_head;
      return res;
    }

    bool is_empty() {
      return head == nullptr;
    }

    void clear() {
      while (!is_empty()) {
        pop();
      }
    }
};

int main() {
  #ifdef local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  GucciQueue q;
  int n;
  std::cin >> n;
  while (n--) {
    char op;
    std::cin >> op;

    if (op == '+') {
      int x;
      std::cin >> x;
      q.push_back(x);
    }

    if (op == '*') {
      int x;
      std::cin >> x;
      q.push_mid(x);
    }

    if (op == '-') {
      std::cout << q.pop() << '\n';
    }
  }
  q.clear();
  
}
