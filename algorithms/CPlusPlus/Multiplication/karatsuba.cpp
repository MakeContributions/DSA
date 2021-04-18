#include <math.h>
#include <iostream>
#include <string>
using namespace std;

int equalize_strings(string &x, string &y) {
  int n = x.length();
  int m = y.length();
  string zeros(abs(n - m), '0');
  if (n > m) {
    y = zeros + y;
  } else if (m > n) {
    x = zeros + x;
  }
  return x.length();
}

string sum(string x, string y) {
  int len = equalize_strings(x, y);
  int carry = 0;
  string result;
  for (int i = 1; i <= len; i++) {
    int dgt1 = x[len - i] - '0';
    int dgt2 = y[len - i] - '0';
    int dgt3 = (dgt1 + dgt2 + carry) % 10;
    result = to_string(dgt3) + result;
    carry = (dgt1 + dgt2 + carry) / 10;
  }
  if (carry) {
    result = '1' + result;
  }
  return result;
}

string subtract(string x, string y) {
  int len = equalize_strings(x, y);
  int carry = 0;
  string result;
  for (int i = 0; i < len; i++) {
    if (y[i] < x[i]) {
      break;
    } else if (x[i] < y[i]) {
      string temp = x;
      x = y;
      y = temp;
      break;
    }
  }
  for (int i = 1; i <= len; i++) {
    int dgt1 = x[len - i] - '0';
    int dgt2 = y[len - i] - '0';
    int dgt3 = dgt1 - dgt2 - carry;
    if (dgt3 < 0) {
      dgt3 += 10;
      carry = 1;
    } else {
      carry = 0;
    }
    result = to_string(dgt3) + result;
  }
  return result;
}

string kmul(string x, string y) {
  int len = equalize_strings(x, y);
  if(len == 1){
    return to_string((x[0]-'0') * (y[0]-'0'));
  }
  int mid = len / 2;
  string a = x.substr(0, mid);
  string b = x.substr(mid, len - mid);
  string c = y.substr(0, mid);
  string d = y.substr(mid, len - mid);
  string ac = kmul(a, c);
  string bd = kmul(b, d);
  string ab_cd = kmul(sum(a, b), sum(c, d));
  string ad_bc = subtract(ab_cd, sum(ac,bd));
  string zeros(len - mid, '0');

  string result = sum(ac + zeros + zeros, ad_bc + zeros);
  result = sum(result, bd);
  result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
  return result;
}

int main() {
  string x, y;
  cin >> x >> y;
  cout << kmul(x, y) << endl;
  return 0;
}
