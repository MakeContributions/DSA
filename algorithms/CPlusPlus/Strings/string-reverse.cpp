#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

string revStr(string s){
    int i = 0, j = s.length()-1;
    
    while (i < j){
        swap(s[i], s[j]);    
        i++; j--;
    }
    return s;
}

int main() {
    string s;
    cout << "Enter the string name: ";
    cin>>s;
    
    // manually reversing it. This is not in-place method, to update the string you would have to do s = revStr(s)
    cout << revStr(s) << endl;
    
    // using a method from algorithm library. This is an in-place method.
    reverse(s.begin(),s.end());
    cout<< s << endl;
    return 0;

}
