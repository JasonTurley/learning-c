/* Ex. 1-9: Write a program to copy its input to its output, replacing each
 * string of one or more blanks by a single blank. */
#include <stdio.h>

main()
{
	int c;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			/* prints only one blank, ignores all others */
			while ((c = getchar()) == ' ')
				;
			putchar(' ');
		}
		putchar(c);
	}
}
