#include<stdio.h>
#include<ctype.h>
int main()
{
  char w;
  printf("Enter the string size and then the string");
  scanf("%d",&s);
  char str[s];
  int i;
  for(i=0;i<s;i++)
    str[i]=getchar();
  printf("Enter letter to be searched");
  scanf("%d",&w);
   for(i=0;i<s;i++)
   {
     if(str[i]==w)
     {
       print("found at %d",i);
       exit();
     }
   }
  print("NO match found");
  return 0;
}

  
  
