/*
Description: Given an vector v containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the vector.

Approach: Using for loop from 0 to n and searching if the value is present in the vector or not using find() function.
If a certain value is not present, the function will return it.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//function starts
int missingNumber(vector<int> &v){
  int num;
  for(int i=0;i<=v.size();i++){
    //checking if i is present or not in the vector
    //if not present,it will store the value of i in the num variable and breaking it
    if(find(v.begin(),v.end(),i)==v.end()){
       num=i;
       break;
    }
  }
  return num;
}

//main starts
int main() {
cout << "Enter number of elements:\n";
int n;
cin>>n;
vector<int> v(n);
cout<<"Enter any "<<n<<" elements (From 0 to "<<n<<") \n";
for(int i=0;i<n;i++){
  cin>>v[i];
}
cout<<"\nMissing number is: "<<missingNumber(v);
return 0;
}

/*
Input:
Enter number of elements:
4
Enter any 4 elements (From 0 to 4) 
0
1
2
3

Output:
Missing number is: 4
*/
