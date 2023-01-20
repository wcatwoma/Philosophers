/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 16:53:56 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/18 16:53:58 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	t_data			data;

	if ((argc != 5 && argc != 6) || parse(&data, argv + 1))
		return (ft_error());
	create_processes(&data);
	wait_processes(&data);
	free_all(data);
	return (0);
}
