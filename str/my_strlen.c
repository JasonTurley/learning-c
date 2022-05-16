/*
 * my_strlen.c - my implementation of the strlen() function call.
 *
 * Date: 16 May 2022
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

size_t my_strlen(const char* s)
{
		size_t len = 0;

		while (s[len] != '\0') {
			len++;
		}

		return len;
}

int main() 
{
		// test cases
		const char* s1 = "hello there!";
		const char* s2 = "";
		const char* s3 = "this is just another test case";

		assert(strlen(s1) == my_strlen(s1));
		assert(strlen(s2) == my_strlen(s2));
		assert(strlen(s3) == my_strlen(s3));

		return 0;
}
