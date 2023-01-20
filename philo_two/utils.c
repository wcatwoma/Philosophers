/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 16:55:25 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/18 16:55:27 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putchar_fd(char *str, int fd)
{
	if (!str)
		return ;
	while (*str)
		write(fd, str++, 1);
}

int		ft_isdigit(int ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	unsigned long	res;
	int				sign;

	res = 0;
	sign = 1;
	while (*str == '\t' || *str == '\f' || *str == '\n'
				|| *str == ' ' || *str == '\r' || *str == '\v')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
		res = res * 10 + (*str++ - '0');
	if (*str && !ft_isdigit(*str))
		return (-1);
	return ((int)res * sign);
}

void	*ft_calloc(size_t num, size_t size)
{
	char	*new;
	size_t	max;

	max = (size_t)~0;
	if ((num && max / num < size) ||
		(size && max / size < num))
		return (NULL);
	num *= size;
	new = malloc(num);
	if (new == NULL)
		return (NULL);
	while (num--)
		*((char*)new + num) = 0;
	return (new);
}

int		ft_error(void)
{
	ft_putchar_fd("Error: bad arguments!\n", 2);
	ft_putchar_fd("Input format: ./philo_one \
number_of_philo time_to_die time_to_eat time_to_sleep \
[number_of_times_each_philosopher_must_eat]\n", 2);
	ft_putchar_fd("Example input: ./philo_one 5 800 200 200 [7]\n", 2);
	return (1);
}
