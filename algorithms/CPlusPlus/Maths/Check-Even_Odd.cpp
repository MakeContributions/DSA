#include <bits/stdc++.h>
using namespace std;

//Function to check whether a number is Odd or not.
//We use a single Odd function to check for Even-Odd, If it return true then it is Odd else it is Even.
bool isOddBin(int num){
    //We compare the last bit of the number to decide for Even or Odd
    //If the last bit of the num is set (i.e. 1) then number is odd and its "Binary And (&)" with the 1 will return true(1).
    //Similarly in case of even num last bit is unset/off (i.e. 0) and its "Binary And (&)" with the 1 will return false(0).
    return (num&1);
} 

bool isOddN(int num){
    //In this we use the Mod(%) operator to check for Even-Odd.
    //If the num is Odd then (num%2) will give 1 and function will return true. 
    //If the num is Even then (num%2) will give 0 and function will return false. 
    return (num%2==1);
}

int main() {
    int num;
    cin >> num; //Taking input from the user
    string result;
    result = isOddBin(num) ? "Odd" : "Even"; //Evaluating string based on result from isOdd function
    cout << result<<endl; //Printing result
    result = isOddN(num) ? "Odd" : "Even"; //Evaluating string based on result from isOdd function
    cout << result; //Printing result
    //Ex : num = 11 , result will print "Odd"
    //Ex : num = 8 , result will print "Even"
    //Time Complexity :O(1)
    //Space Complexity :O(1)
    return 0;
}
