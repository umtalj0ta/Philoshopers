/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:34:48 by jgomes-v          #+#    #+#             */
/*   Updated: 2024/03/01 17:34:49 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct data_general	t_data_gen;

typedef struct s_fork
{
	pthread_mutex_t			fork;
	int						fork_id;
}							t_fork;

typedef struct s_philo
{
	int						id;
	long					meals_count;
	long					last_meal_time;
	t_fork					*left_fork;
	t_fork					*right_fork;
	pthread_t				thread_id;
	t_data_gen				*table;
}							t_philo;

/*
 *
 *  ./philo 5 400 200 200 - first 4 by order in the struct below
 */
typedef struct data_general
{
	int					philo_nbr;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					start_simulation;
	bool					end_simulation;
	t_fork					*forks;
	t_philo					*philos;

}							t_data_gen;

// parsing
void	parse_input(t_data_gen *table, char **argv);

//error
void	error_exit(const char *error);

#endif