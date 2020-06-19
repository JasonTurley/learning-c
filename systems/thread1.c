/*
 * thread1.c - N threads increment shared counter, without mutual exclusion.
 * 31 May 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 1000

int counter = 0;

void *increment(void *unused)
{
	int i;

	for (i = 0; i < N; i++)
		counter++;

	return unused;
}

int main()
{
	pthread_t my_threads[N];
	int i;

	for (i = 0; i < N; i++)
		pthread_create(&my_threads[i], NULL, &increment, NULL);

	/* Wait for all threads to finish before returning from main() */
	for (i = 0; i < N; i++)
		pthread_join(my_threads[i], NULL);

	/* Can you guess what counter will equal? */
	printf("counter: %d\n", counter);

	return 0;
}
