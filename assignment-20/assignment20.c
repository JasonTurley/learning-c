#include <stdio.h>

struct values {
	int i;
	char c;
	float f;
};

int main()
{
	struct values v;

	v.i = 42;
	v.c = 0x41;
	v.f = 69.420;

	printf("The int: %d, the char %d, and the float %f\n", v.i, v.c, v.f);

	return 0;
}
