/*
 * print-twice.c - The following program prints out 42 twice - but the fork() is after the
 * printf!? Why?
 * 
 * Answer: the call to printf is executed only one, but since the line is not flushed with
 * a newline char or fflush(), it still remains in the process memory buffer. When fork 
 * is called the entire process memory is copied over, resulting in the line being printed
 * twice!
 *
 * 6 Mar 2021
 *
 * Source:
 * https://github.com/angrave/SystemProgramming/wiki/Forking%2C-Part-1%3A-Introduction
 */
#include <unistd.h>
#include <stdio.h>

int main() {
	int answer = 82 >> 1;
	printf("The answer is %d", answer);
	//fflush(stdout);	// run again with me uncommented!
	fork();
	return 0;
}
