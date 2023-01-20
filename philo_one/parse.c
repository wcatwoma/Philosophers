/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 16:52:51 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/18 16:52:54 by wcatwoma         ###   ########.fr       */
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
		ids[i].die = 0;
		ids[i].end = 0;
		ids[i].think = 0;
		ids[i].counter = 0;
		ids[i].right = i;
		ids[i].left = i - 1 < 0 ? data->count - 1 : i - 1;
		ids[i].data = data;
		i++;
	}
	return (ids);
}

pthread_mutex_t	*get_mutexs(int count_philosopher)
{
	int				i;
	pthread_mutex_t	*mutexs;

	i = 0;
	mutexs = \
	(pthread_mutex_t*)malloc(sizeof(pthread_mutex_t) * count_philosopher);
	while (i < count_philosopher)
	{
		pthread_mutex_init(mutexs + i, NULL);
		i++;
	}
	return (mutexs);
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
	data->threads = \
		(pthread_t*)malloc(sizeof(pthread_t) * data->count);
	data->deaths = get_mutexs(data->count);
	data->mutexs = get_mutexs(data->count);
	data->count_cycle = argv[4] ? data->count_cycle : -1;
	data->philosophers = \
		get_data_philosophers(data->count, data);
	data->end = 0;
	pthread_mutex_init(&data->mutexs_out, NULL);
	pthread_mutex_init(&data->death, NULL);
	pthread_mutex_init(&data->death2, NULL);
	return (0);
}
