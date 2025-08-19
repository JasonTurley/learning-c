#include <pthread.h>
#include <stdio.h>

int global;

void *Thread1(void *x) {
	global++;
	return NULL;
}

void *Thread2(void *x) {
	global--;
	return NULL;
}

int main() {
	pthread_t thread[2];

	// thread 1 increments
	pthread_create(&thread[0], NULL, Thread1, NULL);

	// thread 2 decrements
	pthread_create(&thread[1], NULL, Thread2, NULL);

	// main thread sets to 100
	global = 100;

	pthread_join(thread[0], NULL);
	pthread_join(thread[1], NULL);

	printf("Global: %d\n", global);
}
