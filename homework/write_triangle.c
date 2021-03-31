/*
 * write_triangle.c - Write a function to print out a triangle of height n to
 * standard error. Your function should have the signature 
 * `void write_triangle(int n)` and should use `write()`.
 *
 * Date: 30 Mar 2021
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Helper function to print n stars
void write_stars(int n)
{
	for (int i = 1; i <= n; i++)
		write(2, "*", 1);	
}

void write_triangle(int n)
{
	int start = 1;
	while (n > 0) {
		write_stars(start);
		start++;
		n--;
		write(2, "\n", 1);
	}
}
	
int main() 
{
	printf("Enter an integer: ");
	fflush(stdout);	// need this for the above to print

	char buf[10];
	read(STDIN_FILENO, buf, 10);
	
	int n = atoi(buf);
	write_triangle(n);

	return 0;
}
