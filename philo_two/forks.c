/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 16:54:48 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/18 16:54:50 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	takes_forks(t_philosopher *philosopher)
{
	sem_wait(philosopher->data->sem_forks);
	print_message(get_lifetime(philosopher), philosopher, "has taken a fork");
	sem_wait(philosopher->data->sem_forks);
	print_message(get_lifetime(philosopher), philosopher, "has taken a fork");
}

void	put_forks(t_philosopher *philosopher)
{
	sem_post(philosopher->data->sem_forks);
	sem_post(philosopher->data->sem_forks);
}
