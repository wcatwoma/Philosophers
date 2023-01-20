/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 16:52:33 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/18 16:52:35 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	takes_forks(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->data->mutexs + philosopher->right);
	print_message(get_lifetime(philosopher), philosopher, \
	"has taken a fork");
	pthread_mutex_lock(philosopher->data->mutexs + philosopher->left);
	print_message(get_lifetime(philosopher), philosopher, \
	"has taken a fork");
}

void	put_forks(t_philosopher *philosopher)
{
	pthread_mutex_unlock(philosopher->data->mutexs + philosopher->left);
	pthread_mutex_unlock(philosopher->data->mutexs + philosopher->right);
}
