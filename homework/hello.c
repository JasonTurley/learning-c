/*
 * hello.c - Write a program that uses write() to print out "Hi! My name
 * is <Your Name>."
 *
 * Date: 30 Mar 2021
 */

#include <unistd.h>
#include <string.h>

int main() {
	char *buf = "Hi! My name is Jason!";
	write(1, buf, strlen(buf));

	return 0;
}
