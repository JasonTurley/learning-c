#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if (argc != 3) {
		fprintf(stderr, "Usage: %s firstname lastname\n", argv[0]);
		return -1;
	}


	printf("Hello, %s %s!!\n", argv[1], argv[2]);
}
