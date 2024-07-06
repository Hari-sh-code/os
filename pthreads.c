#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

void * Thd_Hello(void *data)
{
	sleep(1);
	pthread_detach(pthread_self());
	printf("First Child thread id = %ld \n",pthread_self());
	printf("%s\n","Hello World");
	pthread_exit(NULL);
}

void * Thd_Square(void *data)
{
	sleep(1);
	int val = (long)data;
	pthread_detach(pthread_self());
	printf("Second child thread id = %ld \n", pthread_self());
	printf("Square of %d = %d \n",val,(val*val));
	pthread_exit(NULL);
}

void main()
{
	pthread_t thd1, thd2;
	
	int t1,t2;
	long x = 5;
	
	t1 = pthread_create(&thd1, NULL, Thd_Hello, NULL);
	if(t1)
	{
		printf("Error creating new thread");
		exit(1);
	}
	printf("New thread created: %lu\n", thd1);
	
	t2 = pthread_create(&thd2, NULL, Thd_Square, (long *)x);
	if(t2)
	{
		printf("Error creating new thread");
		exit(1);
	}
	printf("New thread created: %lu\n",thd2);
	
	printf("Exiting main thread..\n");
	pthread_exit(NULL);
}
