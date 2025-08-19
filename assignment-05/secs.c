//NOTE: I know this code is not efficient, but it works and makes me happy :)
#include <stdio.h>

int main()
{
	size_t seconds;
	int hours = 0;

	printf("Enter the amount of seconds: ");
	scanf("%ld", &seconds);

	// Only calculate hours if value is >= 3660
	if (seconds  >= 3660) {
		size_t temp = seconds;
		while (temp > 60) {
			temp = temp / 60;
		}
		hours = temp;
	}


	// Get minutes
	int minutes = (seconds / 60) % 60;

	// Get remaining seconds
	int seconds_left = seconds % 60;

	printf("%ld seconds is %d hours, %d minutes and %d seconds\n", seconds, hours, minutes, seconds_left);

	return 69;
}
