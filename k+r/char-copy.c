#include <stdio.h>

int main()
{
        // EOF is an integer, not a character
        int c;

        while ((c = getchar())!= EOF) {
                putchar(c);
        }

        return 0;
}
