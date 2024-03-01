#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

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
	printf("Sleeping for 1 second...\n");
	usleep(1000000); // sleep for 1 second (100 0000 microseconds)
	printf("Done sleeping.\n");
}

void	exemplo_2(void)
{
	struct timeval	start_time;
	struct timeval	end_time;

	long requested_sleep_time; // em ms
	long actual_sleep_time;    // em ms
	requested_sleep_time = 200 * 1000; // 200 ms * 1000 = 200 micros
	gettimeofday(&start_time, NULL);
	usleep(requested_sleep_time);
	gettimeofday(&end_time, NULL);
	actual_sleep_time = (end_time.tv_sec - start_time.tv_sec) * 1000000
		+ (end_time.tv_usec - start_time.tv_usec);
	printf("Requested Sleep Time : %ld microsegundos\n", requested_sleep_time);
	printf("Actual Sleep Time : %ld microsegundos\n", actual_sleep_time);
}

int	main(void)
{
	exemplo_2();
}