#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *ptr;

	ptr = malloc(100 * sizeof(char));
	if (!ptr) {
		fprintf(stderr, "malloc failed!\n");
		exit(1);
	}

	puts("Successfully allocated a pointer!");
	free(ptr);
	return 0;
}
