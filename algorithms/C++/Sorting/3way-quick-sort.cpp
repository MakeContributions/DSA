#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

void partition(vector<int> &a, int l, int r, int &i, int &j) {
  if (r - l <= 1){
    if (a[r] < a[l])
      swap (a[r], a[l]);

    i = l;
    j = r;
    return;
  }

  int m = l;
  int pivot = a[r];

  while (m <= r) {
    if (a[m] < pivot)
      swap(a[l++], a[m++]);
    else if (a[m] == pivot)
      m++;
    else {
      swap (a[r--], a[m]);
    }
    i = l-1;
    j = m;
  }
}

void quickSort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l +(r - l)/2;
  int i, j;
  partition(a, l, r, i, j);
  quickSort(a, l, i);
  quickSort(a, j, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  //randomized_quick_sort(a, 0, a.size() - 1);
  quickSort(a, 0, a.size()-1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
