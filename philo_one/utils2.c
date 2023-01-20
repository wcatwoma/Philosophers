/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 16:53:27 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/18 16:53:30 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putnbr(long int n, char *str)
{
	if (n < 0)
		n *= -1;
	if (n >= 10)
		ft_putnbr(n / 10, str - 1);
	*str = '0' + n % 10;
}

char	*ft_itoa(int n)
{
	size_t		size;
	long int	copy;
	char		*new;

	copy = n;
	size = 0;
	while (copy)
	{
		copy /= 10;
		size++;
	}
	if (n <= 0)
		size++;
	new = (char*)malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	*(new + size) = '\0';
	if (n < 0)
		*new = '-';
	ft_putnbr(n, (new + --size));
	return (new);
}

void	free_all(t_data data)
{
	int	i;

	i = 0;
	while (i < data.count)
	{
		pthread_mutex_destroy(data.mutexs + i);
		pthread_mutex_destroy(data.deaths + i);
		i++;
	}
	pthread_mutex_destroy(&data.mutexs_out);
	pthread_mutex_destroy(&data.death);
	free(data.threads);
	free(data.mutexs);
	free(data.philosophers);
}

void	print_message(int time, t_philosopher *philosopher, char *message)
{
	char *time_str;
	char *id_str;

	pthread_mutex_lock(&philosopher->data->mutexs_out);
	time_str = ft_itoa(time);
	id_str = ft_itoa(philosopher->id + 1);
	ft_putchar_fd(time_str, 1);
	ft_putchar_fd(" ", 1);
	ft_putchar_fd(id_str, 1);
	ft_putchar_fd(" ", 1);
	ft_putchar_fd(message, 1);
	ft_putchar_fd("\n", 1);
	free(time_str);
	free(id_str);
	pthread_mutex_unlock(&philosopher->data->mutexs_out);
}
