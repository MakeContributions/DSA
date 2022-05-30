#include <iostream>
#include <string>
using namespace std;

void towerOfHanoi(int disks,char stand1,char stand2,char stand3)
{
     if(disks==1)
     {cout<<"Move disk 1 from "<<stand1<<" to "<<stand3<<endl;
      return ;
     }
     towerOfHanoi(disks-1,stand1,stand3,stand2);
     cout<<"Move disk "<<disks<<" from "<<stand1<<" to "<<stand3<<endl;
     towerOfHanoi(disks-1,stand2,stand1,stand3);

}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	towerOfHanoi(n,'A','B','C');
}