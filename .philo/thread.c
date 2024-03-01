#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	*print_hello(void *arg) //-> needs to be void *arg to be used in pthread. can typecast it later on the pthread function
{
	int i = 0;

	while (i < 100)
	{
		printf("Hello\n");
		i++;
		usleep(10000);
	}
	return (NULL);
}

void	*print_world(void *arg) //-> needs to be void *arg to be used in pthread. can typecast it later on the pthread function
{
	int i = 0;

	while (i < 100)
	{
		printf("\t\tWorld\n");
		i++;
		usleep(10000);
	}
	return (NULL);
}

void	*routine(void *arg)
{
	int	*num;
	int	i;

	i = 0;
	num = (int *)arg;
	while (i < 100)
	{
		(*num)++;
		i++;
	}
	return (NULL);
}

void	example_1(void)
{
	print_hello(NULL);
	print_world(NULL);
}

void	example_2(void)
{
	pthread_t	t1;
	pthread_t	t2;

	// to create threads
	if (pthread_create(&t1, NULL, print_hello, NULL) != 0)
		exit(1);
	if (pthread_create(&t2, NULL, print_world, NULL) != 0)
		exit(1);
	// now join them
	if (pthread_join(t1, NULL) != 0)
		exit(1);
	if (pthread_join(t2, NULL) != 0)
		exit(1);
}
void	example_3(void)
{
	int			*num;
	pthread_t	t1;
	pthread_t	t2;

	num = malloc(sizeof(int));
	*num = 0;
	if (pthread_create(&t1, NULL, routine, num) != 0)
		exit(1);
	if (pthread_create(&t2, NULL, routine, num) != 0)
		exit(1);
	if (pthread_join(t1, NULL) != 0)
		exit(1);
	if (pthread_join(t2, NULL) != 0)
		exit(1);
	printf("Num: %d\n", *num);
}

int	main(void)
{
	example_3();
}