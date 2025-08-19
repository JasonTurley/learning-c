#include <stdio.h>

int main()
{
	int numerator;
	int denominator;

	printf("Enter a numerator: ");
	scanf("%d", &numerator);
	
	printf("Enter a denominator: ");
	scanf("%d", &denominator);

	// handles the divide by zero error
	if (denominator <= 0) {
		fprintf(stderr, "Cannot divide by zero!\n");
		return -1;
	}

	if (numerator % denominator)
		printf("There is a remainder!\n");
	else
		printf("There is NOT a remainder!\n");

	return 0;
}
