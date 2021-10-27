/** Starting with an array of zeros and a list of operations, for each operation add a value to each of the array element between two given indices,inclusive.
    Once all operations have been performed,return the maximum value in the array **/
    
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cout<<" Enter the numbers of elements in the array " <<endl;
  cin>>n;
  
  int q;
  cout<<" Enter the number of queries you want to input : ";
  
  vector<vector<int>> queries;
  
  cin>>q;
  
  vector<int> temp;
  
  cout<<"Enter each query in the form : a b k  where a is the start position , b is the end position and k is the value to be added " << endl;
  
  for(int i=0 ; i<q; i++ )
  {
    int a,b,k;
    cin>>a>>b>>k;
    temp.push_back(a);
    temp.push_back(b);
    temp.push_back(k);
    
    queries.push_back(temp);
    }
    
    vector<long> arr;
    
    long max=0;
    
    for(int i=0; i<n ; i++ )
    {
      arr.push_back(0);
     }
     
    for(int i=0 ; i<queries.size(); i++ )
    {
      arr[queries[i][0]] = arr[queries[i][0]] + queries[i][2];          here we taking help of prefix sum algorithm
      
      if(queries[i][1] < n-1 )
      arr[queries[i][1]+1] = arr[queries[i][1] + 1] - queries[i][2];
     
    }
    
    long x = 0 ;
    
    for(int i=0; i<n ; i++ )
    {
       x = x+ arr[i] ;                        
       
       if(x>max)
         max=x;
     }
       cout<<max;
     }
      
    
    
      
