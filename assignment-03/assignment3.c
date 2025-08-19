#include <stdio.h>
#include <string.h>

void main()
{
	char fname[32];
	char lname[32];

	// Get names and strip newline
	printf("Enter your first name: ");
	fgets(fname, sizeof(fname), stdin);
	fname[strcspn(fname, "\n")] = 0;
	

	printf("Enter your last name: ");
	fgets(lname, sizeof(lname), stdin);
	lname[strcspn(lname, "\n")] = 0;

	// say hello!
	printf("Hello %s %s!\n", fname, lname);
}
