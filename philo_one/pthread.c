/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 16:53:03 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/18 16:53:06 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_pthread_detach_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->count)
		pthread_detach(data->threads[i++]);
}

void	ft_pthread_join_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->count)
		pthread_join(data->threads[i++], NULL);
}

void	ft_pthread_wait(t_data *data, int iscounter)
{
	int i;

	pthread_mutex_lock(&data->death);
	pthread_mutex_lock(&data->death);
	if (iscounter && !data->end)
	{
		i = 0;
		while (i < data->count)
		{
			while (!(data->philosophers[i].end))
				;
			i++;
		}
	}
}

void	ft_pthread_create_all(t_data *data)
{
	int	i;

	i = 1;
	while (i < data->count)
	{
		pthread_create(&data->threads[i], NULL, \
		cycle_philosopher, &(data->philosophers[i]));
		i += 2;
	}
	usleep(200);
	i = 0;
	while (i < data->count)
	{
		pthread_create(&data->threads[i], NULL, \
		cycle_philosopher, &(data->philosophers[i]));
		i += 2;
	}
}
