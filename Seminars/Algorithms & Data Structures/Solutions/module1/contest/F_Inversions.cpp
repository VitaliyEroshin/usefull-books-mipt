#include <iostream>
#include <vector>

int mergeSort(std::vector<int>& a, std::vector<int>& buffer, int left, int right) {
  int inversions = 0;

  if (right - left == 1) 
    return 0;

  int mid = (right + left) / 2;

  inversions += mergeSort(a, buffer, left, mid);
  inversions += mergeSort(a, buffer, mid, right);

  int j_left = left, j_right = mid;
  
  for (int i = 0; i < right - left; i++) {
    if (j_right == right) {
      buffer[i] = a[j_left];
      j_left++;
    } else if (j_left == mid) {
      buffer[i] = a[j_right];
      j_right++;
    } else if (a[j_left] <= a[j_right]) {
      buffer[i] = a[j_left];
      j_left++;
    } else {
      buffer[i] = a[j_right];
      inversions += mid - j_left;
      j_right++;
    }
  }

  for (int i = 0; i < right - left; i++) {
    a[left + i] = buffer[i];
  }

  return inversions;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  freopen("inverse.in", "r", stdin);
  freopen("inverse.out", "w", stdout);

  #ifdef local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int n;
  std::cin >> n;
  std::vector<int> a(n), buffer(n);

  for (auto &x : a) 
    std::cin >> x;

  std::cout << mergeSort(a, buffer, 0, n);
  
  
}
