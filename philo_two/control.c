/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 16:54:43 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/18 16:54:45 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*control_philosopher(void *data)
{
	int i;

	while (1)
	{
		((t_philosopher*)data)->eat = 0;
		ft_sleep(((t_philosopher*)data)->data->time_to_die);
		if (!((t_philosopher*)data)->eat)
		{
			sem_wait(((t_philosopher*)data)->data->sem_death);
			if (((t_philosopher*)data)->data->end == 0)
				philosopher_die(((t_philosopher*)data));
			i = 0;
			while (i++ < ((t_philosopher*)data)->data->count)
			{
				sem_post(((t_philosopher*)data)->data->sem_philosophers);
			}
			((t_philosopher*)data)->data->end = 1;
			sem_post(((t_philosopher*)data)->data->sem_death);
			return (NULL);
		}
	}
	return (NULL);
}
