#include <stdio.h>
#include <string.h>

void main()
{
	char *first;
	char *last;

	printf("Enter your first name: ");
	scanf("%ms", &first);	// alloc string
	

	printf("Enter your last name: ");
	scanf("%ms", &last);

	// strip newline chars
	first[strcspn(first, "\n")] = 0;
	last[strcspn(last, "\n")] = 0;

	// say hello!
	printf("Hello %s %s!\n", first, last);

	free(first);
	free(last);
}
