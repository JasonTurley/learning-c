/*
 * Calculates the area of a circle using the formula:
 * 	area = π × radius^2
 */

#include <stdio.h>
#include <stdlib.h>

#define PIE (3.14)

void main()
{
	float radius;
	float area;

	printf("Enter the radius of your circle: ");

	scanf("%f", &radius);

	area = PIE * (radius * radius);
	printf("The area of your circle is %f\n", area);
}
