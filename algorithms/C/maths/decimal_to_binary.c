// This program is used to convert decimal numbers to their binary equivalent

#include <stdio.h>
void decimal_to_binary(int number)
{
	int i = 0;
	int binary[32];

	while(number > 0)
	{
		binary[i] = number % 2;
		number = number / 2;
		i++;
	}

	for(int j = i - 1; j >= 0; j--)
	{
		printf("%d ",binary[j]);
	}
}

int main()
{
	int number;
	scanf("%d",&number);
	decimal_to_binary(number);
}
