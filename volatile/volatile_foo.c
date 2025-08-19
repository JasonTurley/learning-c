/*
 * Compile with:
 * gcc volatile_foo.c -o volatile_foo 
 * gcc volatile_foo.c -o volatile_foo_O2 -O2
 */

int main() {
	volatile int foo;
	foo = 1;
	foo++;
}
