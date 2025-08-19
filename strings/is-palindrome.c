/*
 * Tests if the entered string is a palindrome.
 *
 * i.e. racecar, mom, dad are all palindromes.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

// first, naive implementation
bool is_palindrome_naive(const char *s) {

	int j = strlen(s) - 1;

	for (int i = 0; i < j / 2; i++) {
		if (s[i] != s[j])
			return false;
		j--;
	}	

	return true;

}

// second try, code a bit cleaner
bool is_palindrome(const char *s) {

	int i = 0;
	int j = strlen(s) - 1;

	while (i < j) {
		if (s[i++] != s[j--])
			return false;
	}	

	return true;

}
int main() {
	assert(true == is_palindrome("racecar"));
	assert(true == is_palindrome("mom"));
	assert(false == is_palindrome("cooked"));
}
