// This program is used to check if a given no is armstrong number or not in C
// an armstrong number is a number that equals the sum of its digits, each raised to a power.
// power is the number of digits in the number eg. 123 has three digits, so power will be 3.

#include<stdio.h>
#include<math.h>

int main(){                             //main function
    int num,digit=0,temp,sum=0;         //define variables
    printf("enter the number: ");       
    scanf("%d",&num);                   //taking inputs
    temp=num;
    while(temp>0){
        digit++;                        //counting number of digits in the input number
        temp=temp/10;
    }
    printf("Number of digits: %d\n",digit);
    temp=num;
    while(temp>0){
        sum=sum+ (int)(pow(temp%10, digit)+0.5);    // checking the armstrong property of the number
        temp/=10;                                   // we extract a digit from number using (temp%10) then 
    }                                               // raise that digit to number of digits in the number using pow function
                                                    // (pow()+0.5) is used to increase precision
    printf("Sum of powered digits: %d\n",sum);
    if(num==sum){                                   //checking if the new number is equal to the input number
        printf("Armstrong");
    }
    else{
        printf("Not Armstrong");
    }
    return 0;
}

//         Input        ||       Output
//          153         ||      Armstrong
//          371         ||      Armstrong
//          1634        ||      Armstrong
//          123         ||      Not Armstrong

// This program has time complexity of O(N).
