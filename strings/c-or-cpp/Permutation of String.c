#include<stdio.h>
//declare functions
void permutation(char *,int,int);
void swap(char *,char *);
main()
{
    char s[10];
	//taking string
    printf("enter string");
    scanf("%s",&s);
	//calling permutation
    permutation(&s,0,strlen(s)-1);
    getch();
}
void permutation(char *str,int s,int e)
{   //declare variables
    static int count;
    int i;
	//base condition
    if(s==e)
    {
        count++;
        printf("%d(%s)\n",count,str);
    }
    else
    {
        for(i=s;i<=e;i++)
        {  //swapping variables value
            swap(str+s,str+i);
			//calling permutation function
            permutation(str,s+1,e);
			//now swap the variables value and make it before one 
            swap(str+s,str+i);
        }
    }
}
//swap function
void swap(char *a,char *b)
{
    char temp;
	//putting value in temp
    temp=*a;
	// putting value in a pointer
    *a=*b;
	//now putting value of temp in b pointer
    *b=temp;
	//swapping done 
}
// Example:
//Input: abc
//Output: 1(abc)                                                                                                                        
//        2(acb)                                                                                                                        
//        3(bac)                                                                                                                        
//        4(bca)                                                                                                                        
//        5(cba)     
//        6(cab)                                                                                                                        
