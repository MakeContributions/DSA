/*
 Program to print an array of the next greater element to the element with index i
 */
#include<bits/stdc++.h>
using namespace std;
/*
   Logic
   1. Create an empty stack and the nextGreater array.
   2. Loop over the given array (let's call it arr).
   3. While arr[i] > arr[top of the stack], assign arr[i] to nextGreater[top of the stack].
   4. Then push i to the stack.
   This way, you've created a nextGreater array.
  */
int main() {
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    stack<int> st;
    int nextGreater[n];

    for(int i=0;i<n;i++){
        nextGreater[i]=arr[i];
        while(!st.empty() and arr[i]>arr[st.top()]){
            nextGreater[st.top()]=arr[i];
            st.pop();
        }
        st.push(i);
    }
    for(int i=0;i<n;i++)
        cout<<nextGreater[i]<<" ";
    return 0;
}
/*
input-------------
5
3 2 4 1 5
output-------------
4 4 5 5 5

 */


