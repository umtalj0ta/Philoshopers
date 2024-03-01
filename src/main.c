/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:34:26 by jgomes-v          #+#    #+#             */
/*   Updated: 2024/03/01 17:35:39 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char *argv[])
{
	t_data_gen	table;

	if (argc == 5)
	{
		// 1) parsing
		parse_input(&table, argv);
    error_exit("Deu bem");
 
		// 2) create the table and init all
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
