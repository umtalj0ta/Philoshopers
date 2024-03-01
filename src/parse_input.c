
#include "../include/philo.h"

static inline bool	is_space(char c)
{
	return ((c >= 9 && c <= 13) || 32 == c);
}

static inline bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static const char	*valid_input(const char *str)
{
	const char	*number;

	while (is_space(*str))
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
		error_exit("Only positive value");
	if (!is_digit(*str))
		error_exit("Only digits in input");
	number = str;
	return (number);
}

static int	ft_atoi(const char *str)
{
	int		num;
	long	buffer;

	buffer = 0;
	str = valid_input(str);
	while (is_digit(*str))
	{
		buffer = (buffer * 10) + *str - 48;
		str++;
	}
	if (buffer > INT_MAX)
		error_exit("Less than int max");
	num = buffer;
	return (num);
}

void	parse_input(t_data_gen *table, char **argv)
{
	table->philo_nbr = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]) * 1e3;
	table->time_to_eat = ft_atoi(argv[3]) * 1e3;
	table->time_to_sleep = ft_atoi(argv[4]) * 1e3;
	if (table->time_to_sleep < 6e4 || table->time_to_eat < 6e4 
		|| table->time_to_die < 6e4)
		error_exit("your timestamp should be higher than 60ms");
}
