/*
 * thread2.c - N threads increment shared counter, with mutual exclusion.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 1000

static pthread_mutex_t my_mutex = PTHREAD_MUTEX_INITIALIZER;

int counter = 0;

void *increment(void *unused)
{
	int i;

	/* Protect the critical section */
	pthread_mutex_lock(&my_mutex);
	for (i = 0; i < N; i++)
		counter++;
	pthread_mutex_unlock(&my_mutex);

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
