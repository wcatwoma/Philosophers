/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 16:53:09 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/18 16:53:11 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((tv.tv_sec * (long)1000) + (tv.tv_usec / (long)1000)));
}

int		get_lifetime(t_philosopher *philosopher)
{
	long	time;

	time = get_time();
	return (time - philosopher->time_start);
}

void	ft_sleep(int t)
{
	long int	s;
	long int	e;

	s = get_time();
	while (1)
	{
		usleep(200);
		e = get_time();
		if (e - s >= (long int)t)
			return ;
	}
}
