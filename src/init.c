/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:34:21 by jgomes-v          #+#    #+#             */
/*   Updated: 2024/03/01 17:55:10 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// void    init_forks()
// {
// 	//TODO
// }


void	philo_init(t_data_gen *table)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < table->philo_nbr)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		//philo->full = FALSE;
		philo->meals_count = 0;
		philo->table = table;
		i++;
	}
}

void	data_init(t_data_gen *table)
{
	int i;

	i = 0;
	table->philos = malloc(sizeof(table->philo_nbr));
	if (table->philo_nbr == NULL)
		error_exit("failure in allocating table->philos :'( ");
	table->forks = malloc(sizeof(table->philo_nbr));
	if (table->forks == NULL)
		error_exit("Failure memory");
	while (i < table->philo_nbr)
	{
		//INIT THE MUTEX TODO

		i++;
	}
	philo_init(&table); //TODO
}