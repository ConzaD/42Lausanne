/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:29:05 by dconza            #+#    #+#             */
/*   Updated: 2024/09/09 17:01:57 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_valid_positive_number(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (ft_atoi(str) <= 0)
		return (0);
	return (1);
}

void	freeall(t_info *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philo)
	{
		pthread_mutex_destroy(&data->philo[i].fork_l);
		pthread_mutex_destroy(data->philo[i].fork_r);
	}
	free(data->philo);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->m_stop);
	pthread_mutex_destroy(&data->m_eat);
	pthread_mutex_destroy(&data->dead);
}

int	main(int ac, char **av)
{
	t_info	data;
	int		i;

	i = 1;
	if (ac != 5 && ac != 6)
		return (1);
	while (i < ac)
	{
		if (!is_valid_positive_number(av[i]))
			return (1);
		i++;
	}
	if (var_init(&data, av) == 1)
	{
		free(data.philo);
		return (0);
	}
	philo_init(&data);
	freeall(&data);
	return (0);
}
