#include <iostream>
 using namespace std;
 float square_root(int a,int p){
     int s=0;
     int e=a;
     float ans=-1;
     int mid;
     while(s<=e){
         mid=(s+e)/2;
         if (mid*mid==a)
         return mid;
         else if(mid*mid<a){
         s=mid+1;
         ans=mid;
         }
         else
         e=mid-1;
     }
   float inc=0.1;
   for(int times=1;times<=p;times++){
       while(ans*ans<=a){
           ans=ans+inc;
       }
       ans=ans-inc;
       inc=inc/10;

   }  
 return ans;
 }


 int main() {
     int n;
     cin>>n;

     cout<<square_root(n,3);


 }
