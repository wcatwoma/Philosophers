/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 16:53:49 by wcatwoma          #+#    #+#             */
/*   Updated: 2021/07/18 16:53:51 by wcatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>

struct s_philosopher;
struct timeval				time_start;
struct timeval				time_point;

typedef struct				s_data
{
	int						count;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						count_cycle;
	sem_t					*sem_out;
	sem_t					*sem_forks;
	sem_t					*sem_death;
	sem_t					*sem_philosophers;
	pid_t					*processes;
	struct s_philosopher	*philosophers;
}							t_data;

typedef struct				s_philosopher
{
	int						id;
	int						eat;
	int						counter;
	long					time_start;
	t_data					*data;
}							t_philosopher;

void						ft_putchar_fd(char *str, int fd);
int							ft_isdigit(int ch);
int							ft_atoi(const char *str);
char						*ft_itoa(int n);
void						*ft_calloc(size_t num, size_t size);
int							ft_error(void);
void						takes_forks(t_philosopher *philosopher);
void						put_forks(t_philosopher *philosopher);
void						*control_philosopher(void *data);
void						*cycle_philosopher(void *data);
int							get_permission_for_forks(t_philosopher *p);
void						philosopher_die(t_philosopher *philosopher);
void						philosopher_eat(t_philosopher *philosopher);
void						philosopher_sleep(t_philosopher *philosopher);
void						philosopher_think(t_philosopher *philosopher);
int							parse(t_data *data, char **argv);
void						free_all(t_data data);
void						ft_pthread_detach_all(t_data *data);
void						create_processes(t_data *data);
void						print_message(int time, t_philosopher *p, char *m);
long						get_time(void);
int							get_lifetime(t_philosopher *philosopher);
void						ft_sleep(int t);
void						wait_processes(t_data *data);

#endif
