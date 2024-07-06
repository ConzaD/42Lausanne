/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:26:50 by dconza            #+#    #+#             */
/*   Updated: 2024/07/06 15:50:06 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_num(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	var_init(t_info *data, char **av)
{
	if (check_num(av))
		return (1);
	data->n_philo = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (av[5] != NULL)
		data->n_eat = ft_atoi(av[5]);
	else
		data->n_eat = -1;
	if (data->n_eat == 0)
		return (1);
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->m_stop, NULL);
	pthread_mutex_init(&data->m_eat, NULL);
	pthread_mutex_init(&data->dead, NULL);
	data->stop = 0;
	data->philo_eat = 0;
	data->philo = malloc(sizeof(t_philo) * data->n_philo);
	if (data->philo == NULL)
		return (2);
	return (0);
}

int	init_philosopher(t_philo *philo, t_info *data, int i)
{
	philo->n = i;
	philo->last_eat = 0;
	philo->fork_r = NULL;
	philo->info = data;
	philo->m_count = 0;
	if (pthread_mutex_init(&(philo->fork_l), NULL) != 0)
		return (-1);
	if (i - 1 == data->n_philo - 1)
		philo->fork_r = &data->philo[0].fork_l;
	else
		philo->fork_r = &data->philo[i].fork_l;
	return (0);
}

int	create_threads(t_info *data)
{
	int	i;

	i = 0;
	while (++i <= data->n_philo)
	{
		if (pthread_create(&data->philo[i - 1].thread, NULL,
				&philo_life, &(data->philo[i - 1])) != 0)
			return (-1);
	}
	return (0);
}

int	philo_init(t_info *data)
{
	int	i;

	data->t_start = timestamp();
	i = 0;
	while (++i <= data->n_philo)
	{
		if (init_philosopher(&data->philo[i - 1], data, i) != 0)
			return (-1);
	}
	if (create_threads(data) != 0)
		return (-1);
	i = 0;
	while (++i <= data->n_philo)
		if (pthread_join(data->philo[i - 1].thread, NULL) != 0)
			return (-1);
	return (0);
}

/*int	philo_init(t_info *data)
{
	int	i;

	data->t_start = timestamp();
	i = 0;
	while (++i <= data->n_philo)
	{
		data->philo[i - 1].n = i;
		data->philo[i - 1].last_eat = 0;
		data->philo[i - 1].fork_r = NULL;
		data->philo[i - 1].info = data;
		data->philo[i - 1].m_count = 0;
		if (pthread_mutex_init(&(data->philo[i - 1].fork_l), NULL) != 0)
			return (-1);
		if (i - 1 == data->n_philo - 1)
			data->philo[i - 1].fork_r = &data->philo[0].fork_l;
		else
			data->philo[i - 1].fork_r = &data->philo[i].fork_l;
		if (pthread_create(&data->philo[i - 1].thread,
		 NULL, &philo_life, &(data->philo[i - 1])) != 0)
			return (-1);
	}
	i = 0;
	while (++i < data->n_philo)
		if (pthread_join(data->philo[i - 1].thread, NULL) != 0)
			return (-1);
	return (0);
}*/
