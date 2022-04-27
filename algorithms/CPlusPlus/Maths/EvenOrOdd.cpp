#include <iostream>

using namespace std;

bool isEven(int x){
  if (x%2 == 0){
    return 1;
  } else {
    return 0;
  }
};

bool isOdd(int x){
  if (x%2 > 0){
    return 1;
  } else {
    return 0;
  }
}

int main(){

  cout << isEven(24) << endl;
  cout << isEven(27) << endl;
  cout << isOdd(27) << endl;
  cout << isOdd(24) << endl;

}

  
  
