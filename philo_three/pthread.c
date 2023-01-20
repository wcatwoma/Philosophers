/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 16:54:13 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/18 16:54:15 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	wait_processes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->count)
	{
		sem_wait(data->sem_philosophers);
		sem_wait(data->sem_philosophers);
		i++;
	}
	i = -1;
	while (++i < data->count)
		kill(data->processes[i], SIGKILL);
}

void	create_processes(t_data *data)
{
	int i;

	i = 1;
	while (i < data->count)
	{
		if (!(data->processes[i] = fork()))
		{
			cycle_philosopher(&(data->philosophers[i]));
		}
		i += 2;
	}
	usleep(50);
	i = 0;
	while (i < data->count)
	{
		if (!(data->processes[i] = fork()))
		{
			cycle_philosopher(&(data->philosophers[i]));
		}
		i += 2;
	}
}
