/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 09:10:44 by smihata           #+#    #+#             */
/*   Updated: 2023/08/22 10:38:45 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_kill_error(void)
{
	write(STDERR_FILENO, "Error: Failed to send a kill signal.\n", 39);
	exit(1);
}

static void	send_char(pid_t pid, char c)
{
	int	bits;
	int	error;

	bits = 7;
	while (bits >= 0)
	{
		if (c & (1 << bits))
			error = kill(pid, SIGUSR1);
		else
			error = kill(pid, SIGUSR2);
		if (error == -1)
			ft_kill_error();
		bits--;
		usleep(100);
	}
}

static void	send_str(pid_t pid, char *s)
{
	while (*s)
	{
		send_char(pid, *s);
		s++;
	}
}

// static void	send_reset(pid_t pid)
// {
// 	size_t	i;
// 	int		error;

// 	i = 0;
// 	while (i < 8)
// 	{
// 		error = kill(pid, SIGUSR2);
// 		if (error == -1)
// 			ft_kill_error();
// 		i++;
// 		usleep(800);
// 	}
// }

int	valid_process(pid_t pid)
{
	int	r;

	if (!(100 <= pid && pid <= 99998))
	{
		write(STDERR_FILENO, "Error: Invalid pid\n", 19);
		exit(1);
	}
	r = kill(pid, 0);
	if (r == 0)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3)
	{
		write(STDERR_FILENO, "Error: Invalid argument\n", 24);
		return (1);
	}
	if (!is_int(argv[1]))
	{
		write(STDERR_FILENO, "Error: argument is not int.\n", 28);
		exit(1);
	}
	pid = (pid_t)ft_atoi(argv[1]);
	if (valid_process(pid))
		send_str(pid, argv[2]);
	else
	{
		write(STDERR_FILENO,
			"Error: The process ID does not exist", 36);
		write(STDERR_FILENO,
			" or is not allowed to send signals.\n", 36);
		return (1);
	}
	return (0);
}
