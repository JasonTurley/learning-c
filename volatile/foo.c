/*
 * Compile with:
 * gcc foo.c -o foo
 * gcc foo.c -o foo_O2 -O2
 */

int main() {
	// a compiler might optimize this and store 2 inside foo instead of 1
	int foo;
	foo = 1;
	foo++;
}
