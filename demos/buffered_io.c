#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

	printf("No newline!");
	fflush(stdout);

	sleep(2);

	printf("This is cool!");
}
