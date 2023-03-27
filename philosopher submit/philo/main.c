/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohmatsu <kohmatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 22:45:36 by kohmatsu          #+#    #+#             */
/*   Updated: 2023/03/27 12:06:11 by kohmatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	kill_philo(t_philo *philo)
{
	int	i;

	i = 0;
	printf("%zu %d died\n", get_timestamp() - philo->info->start, philo->number);
	pthread_mutex_lock(&(philo->info->dead_or_alive_lock));
	while (i < philo->info->philo_num)
	{
		philo->info->philo[i].dead_or_alive = DIED;
		i++;
	}
	pthread_mutex_unlock(&(philo->info->dead_or_alive_lock));
}

void	print_log(t_philo *philo, int option)
{
	size_t	time;
	int		dead_or_alive;
	int		status;
	
	pthread_mutex_lock(&(philo->info->log_lock));
	pthread_mutex_lock(&(philo->info->time_lock));
	time = philo->info->log;
	pthread_mutex_unlock(&(philo->info->time_lock));
	pthread_mutex_lock(&(philo->info->dead_or_alive_lock));
	dead_or_alive= philo->dead_or_alive;
	pthread_mutex_unlock(&(philo->info->dead_or_alive_lock));
	pthread_mutex_lock(&(philo->info->status_lock));
	status= philo->status;
	pthread_mutex_unlock(&(philo->info->status_lock));
	if (dead_or_alive == LIVE && option == DIED)
		kill_philo(philo);
	else if (status == THINKING && option == FORK
		&& dead_or_alive == LIVE)
		printf("%zu %d has taken a fork\n",
			time - philo->info->start, philo->number);
	else if (status == THINKING && dead_or_alive == LIVE)
		printf("%zu %d is thinking\n", time - philo->info->start, philo->number);
	else if (status == EATING && dead_or_alive == LIVE)
		printf("%zu %d is eating\n", time - philo->info->start, philo->number);
	else if (status == SLEEPING && dead_or_alive == LIVE)
		printf("%zu %d is sleeping\n", time - philo->info->start, philo->number);
	pthread_mutex_unlock(&(philo->info->log_lock));
}

static void	finish(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->philo_num)
		pthread_mutex_destroy(&(info->fork[i]));
	pthread_mutex_destroy(&(info->time_lock));
	pthread_mutex_destroy(&(info->log_lock));
	pthread_mutex_destroy(&(info->meal_lock));
	pthread_mutex_destroy(&(info->dead_or_alive_lock));
	pthread_mutex_destroy(&(info->status_lock));
	if (info->philo)
		free(info->philo);
	if (info->fork)
		free(info->fork);
}

static void	simulation(t_philo *philo)
{
	int	status;

	if (philo->number % 2 == 1)
		usleep(200);
	pthread_create(&(philo->monitor), NULL, (void *)monitoring, philo);
	pthread_detach(philo->monitor);
	while (1)
	{
		take_fork(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
		pthread_mutex_lock(&(philo->info->dead_or_alive_lock));
		status = philo->dead_or_alive;
		pthread_mutex_unlock(&(philo->info->dead_or_alive_lock));
		if (status == DIED || status == ENOUGH)
			return ;
	}
}

int	main(int argc, char **argv)
{
	t_info	info;
	int		i;

	if (check_argv(argc, argv))
		return (ERROR);
	if (info_init(&info, argc, argv))
	{
		finish(&info);
		return (1);
	}
	i = 0;
	while (i < info.philo_num)
	{
		pthread_create(&(info.philo[i].life), NULL,
			(void *)simulation, &(info.philo[i]));
		i++;
	}
	i = 0;
	while (i < info.philo_num)
	{
		pthread_join(info.philo[i].life, (void *)&(info.philo[i]));
		i++;
	}
	finish(&info);
	return (0);
}
