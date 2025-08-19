#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define HEADS (0)
#define TAILS (1)


int main()
{
	// Set random seed on each run
	srand(time(NULL));

	unsigned int flips;
	unsigned int heads = 0;
	unsigned int tails = 0;

	printf("How many times would you like to flip the coin?\n>> ");
	scanf("%d", &flips);

	for (int i = 0; i < flips; i++) {
		if (rand() % 2 == HEADS)
			heads++;
		else
			tails++;
	}

	printf("\nYou flipped the coin %d times:\n", flips);
	printf("\t%d heads\n", heads);
	printf("\t%d tails\n", tails);
}
