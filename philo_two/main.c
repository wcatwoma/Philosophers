/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 16:54:59 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/18 16:55:01 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	int				i;
	t_data			data;
	t_philosopher	*ids;

	if ((argc != 5 && argc != 6) || parse(&data, argv + 1))
		return (ft_error());
	ft_pthread_detach_all(&data);
	ft_pthread_create_all(&data);
	ft_pthread_wait(&data);
	free_all(data);
	return (0);
}
