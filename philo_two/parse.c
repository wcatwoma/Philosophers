/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 16:55:04 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/18 16:55:06 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_philosopher	*get_data_philosophers(int count_philosopher, t_data *data)
{
	int				i;
	t_philosopher	*ids;

	i = 0;
	ids = (t_philosopher*)malloc(sizeof(t_philosopher) * count_philosopher);
	while (i < count_philosopher)
	{
		ids[i].id = i;
		ids[i].eat = 0;
		ids[i].counter = 0;
		ids[i].data = data;
		i++;
	}
	return (ids);
}

int				parse(t_data *data, char **argv)
{
	data->count_cycle = -1;
	if ((data->count = ft_atoi(argv[0])) <= 0 ||
		(data->time_to_die = ft_atoi(argv[1])) <= 0 ||
		(data->time_to_eat = ft_atoi(argv[2])) <= 0 ||
		(data->time_to_sleep = ft_atoi(argv[3])) <= 0 ||
		(argv[4] && (data->count_cycle = ft_atoi(argv[4])) <= 0))
		return (1);
	sem_unlink("forks");
	sem_unlink("out");
	sem_unlink("death");
	sem_unlink("philosophers");
	data->threads = (pthread_t*)malloc(sizeof(pthread_t) * data->count);
	data->sem_forks = sem_open("forks", O_CREAT, 0700, data->count);
	data->sem_out = sem_open("out", O_CREAT, 0700, 1);
	data->sem_death = sem_open("death", O_CREAT, 0700, 1);
	data->sem_philosophers = sem_open("philosophers",\
		O_CREAT, 0700, data->count);
	data->count_cycle = argv[4] ? data->count_cycle : -1;
	data->philosophers = get_data_philosophers(data->count, data);
	data->end = 0;
	return (0);
}
