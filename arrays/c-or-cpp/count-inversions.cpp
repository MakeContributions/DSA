// Algorithm Type: Divide & Conquer
// Time Complexity: O(n*log(n))

#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
using namespace std;

long long int count_split_inv(vector<int> &vec, vector<int> &left, vector<int> &right) {
  long long int split_inv = 0;
  int ridx = 0, lidx = 0;
  int size = vec.size();
  int lsize = left.size();
  int rsize = right.size();
  for (int i = 0; i < size; i++) {
    if (lidx != lsize && ridx != rsize) {
      if (right[ridx] <= left[lidx]) {
        vec[i] = right[ridx];
        ridx++;
        split_inv += lsize - lidx;
      } else {
        vec[i] = left[lidx];
        lidx++;
      }
    } else if (lidx == lsize) {
      vec[i] = right[ridx];
      ridx++;
    } else if (ridx == rsize) {
      vec[i] = left[lidx];
      lidx++;
    }
  }
  return split_inv;
}

long long int count_inversions(vector<int> &vec) {
  int size = vec.size();
  if (size == 1) {
    return 0;
  }
  vector<int> left(vec.begin(), vec.begin() + size / 2);
  vector<int> right(vec.begin() + size / 2, vec.end());
  long long int left_inv = count_inversions(left);
  long long int right_inv = count_inversions(right);
  long long int split_inv = count_split_inv(vec, left, right);

  return left_inv + right_inv + split_inv;
}

int main() {
  vector<int> v{8, 2, 1, 5, 7, 3, 9, 2, 0, 1};
  cout << count_inversions(v) << endl;
  return 0;
}
