#include "../include/philo.h"

/*
 *
 *   ./philo 5 200 400 100
 *         ac2 ac3 ac4 ac5  
 *         av1 av2 av3 av4
 */

int	main(int argc, char *argv[])
{
	t_data_gen	table;

	if (argc == 5)
	{
		// 1) check erros and fill data_gen
		parse_input(&table, argv);
    error_exit("Deu bem");
 
		// 2) create the table
		data_init(&table); // TODO
		
    // 3) simulation
		// start_simulation(&table); // TODO
		
    // 4) - when phillos are full or someone dies | leaks = 0;
		// flush(&table); // TODO
	}
	else
	{
		 error_exit("Wrong input should be ./philo 3 450 200 100");
	}
}
