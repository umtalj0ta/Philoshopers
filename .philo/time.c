//exemplo funçao time()

#include <stdio.h>
#include <sys/time.h> //header da funcao gettimeofday
#include <unistd.h>   //header do usleep

/////////////////////////////////////
// struct timeval {
//              time_t       tv_sec;   /* seconds since Jan. 1, 1970 */
//              suseconds_t  tv_usec;  /* and microseconds */
//      };
//
// 1 segundo = 1 000 000 microsegundos
// 1 segundos = 1 000 milisegundos
// 1 hora = 3 600 segundos
// 1 milisegundo = 1 000 microsegundos
// 10 milisegundos = 10 000 microsegundos
//
//          / 1000          / 1000
//          <---            <---
//  segundos -- milisegundos -- micro segundos
//          --->            --->
//         * 1000          * 1000
//////

void	exemplo_1(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return ;
	printf("%ld seconds\n", time.tv_sec);
	printf("%d microseconds\n", time.tv_usec);
	printf("%ld anos desde 1 de Jan de 1970", time.tv_sec / 60 / 60 / 24 / 365);
}

int	get_time(void) // retorna tempo em milisegundos
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (1);
	return (tv.tv_sec * 1000 + (tv.tv_usec / 1000));
}

void	exemplo_2(void)
{
	int	start_time;
	int	now;

	start_time = get_time();
	usleep(10000); // 10 milisegundos ou 10 000 microsegundos
	now = get_time();
	printf("%d milisegundos passaram desde o start", now - start_time);
}

int	main(void)
{
	exemplo_2();
}