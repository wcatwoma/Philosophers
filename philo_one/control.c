/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 16:52:25 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/18 16:52:29 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*control_philosopher(void *data)
{
	while (!((t_philosopher*)data)->end)
	{
		((t_philosopher*)data)->eat = 0;
		ft_sleep(((t_philosopher*)data)->data->time_to_die);
		if (((t_philosopher*)data)->end)
			return (NULL);
		if (!((t_philosopher*)data)->eat)
		{
			pthread_mutex_lock(&(((t_philosopher*)data)->data->death2));
			philosopher_die(((t_philosopher*)data));
			((t_philosopher*)data)->data->end = 1;
			pthread_mutex_unlock(&(((t_philosopher*)data)->data->death));
			return (NULL);
		}
	}
	return (NULL);
}
