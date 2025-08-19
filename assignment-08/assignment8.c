#include <stdio.h>

int main()
{
	int num;

	printf("Enter a number between 1 and 500: ");
	scanf("%d", &num);

	if (num >=1 && num <= 100)
		printf("You number is between 1 and 100!\n");
	else if (num > 100 && num <= 200)
		printf("You number is between 101 and 200!\n");
	else if (num > 200 && num <= 300)
		printf("You number is between 201 and 300!\n");
	else if (num > 300 && num <= 400)
		printf("You number is between 301 and 400!\n");
	else if (num > 400 && num <= 500)
		printf("You number is between 401 and 500!\n");
	else
		printf("Your number is out of range!\n");

	return 0;

}
