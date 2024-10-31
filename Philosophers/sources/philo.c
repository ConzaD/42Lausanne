/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:22:06 by dconza            #+#    #+#             */
/*   Updated: 2024/09/09 16:55:28 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*check_death(void *phi)
{
	t_philo	*philo;

	philo = (t_philo *)phi;
	ft_usleep(philo->info->t_die + 1);
	pthread_mutex_lock(&philo->info->m_eat);
	pthread_mutex_lock(&philo->info->m_stop);
	if (!is_dead(philo, 0) && timestamp() - \
			philo->last_eat >= (long)(philo->info->t_die))
	{
		pthread_mutex_unlock(&philo->info->m_eat);
		pthread_mutex_unlock(&philo->info->m_stop);
		printf("%lld %d died\n", timestamp(), philo->n);
		is_dead(philo, 1);
	}
	pthread_mutex_unlock(&philo->info->m_eat);
	pthread_mutex_unlock(&philo->info->m_stop);
	return (NULL);
}

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->fork_l));
	if (is_dead(philo, 0))
		return ;
	printf("%lld %d has taken a fork left\n", timestamp(), philo->n);
	if (philo->info->n_philo == 1)
	{
		ft_usleep(philo->info->t_die * 2);
		return ;
	}
	if (is_dead(philo, 0))
		return ;
	pthread_mutex_lock((philo->fork_r));
	printf("%lld %d has taken a fork right\n", timestamp(), philo->n);
}

void	philo_eat(t_philo *philo)
{
	if (is_dead(philo, 0))
		return ;
	printf("%lld %d is eating\n", timestamp(), philo->n);
	pthread_mutex_lock(&(philo->info->m_eat));
	philo->last_eat = timestamp();
	philo->m_count++;
	pthread_mutex_unlock(&(philo->info->m_eat));
	ft_usleep(philo->info->t_eat);
	pthread_mutex_unlock((philo->fork_r));
	pthread_mutex_unlock(&(philo->fork_l));
	if (is_dead(philo, 0))
		return ;
	printf("%lld %d is sleeping\n", timestamp(), philo->n);
	ft_usleep(philo->info->t_sleep);
	if (is_dead(philo, 0))
		return ;
	printf("%lld %d is thinking\n", timestamp(), philo->n);
}

void	*philo_life(void *phi)
{
	t_philo		*philo;
	pthread_t	t;

	philo = (t_philo *)phi;
	if (philo->n % 2 == 0)
		ft_usleep(philo->info->t_eat / 10);
	while (!is_dead(philo, 0))
	{
		pthread_create(&t, NULL, check_death, phi);
		take_fork(philo);
		philo_eat(philo);
		pthread_detach(t);
		if (philo->m_count == philo->info->n_eat)
		{
			pthread_mutex_lock(&philo->info->m_stop);
			if (++philo->info->philo_eat == philo->info->n_philo)
			{
				pthread_mutex_unlock(&philo->info->m_stop);
				is_dead(philo, 2);
			}
			pthread_mutex_unlock(&philo->info->m_stop);
			return (NULL);
		}
	}
	return (NULL);
}
