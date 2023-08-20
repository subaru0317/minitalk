/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 09:10:44 by smihata           #+#    #+#             */
/*   Updated: 2023/08/20 15:24:37 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

static void	ft_kill_error()
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(0);
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
			ft_error();
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

static void	send_reset(pid_t pid)
{
	size_t	i;
	int		error;

	i = 0;
	while (i < 8)
	{
		error = kill(pid, SIGUSR2);
		if (error == -1)
			ft_error();
		i++;
		usleep(800);
	}
}

int	exist_process(pid_t pid)
{
	int	r;

	r = kill(pid, 0);
	if (r == 0)
		return (1);
	return (0);
}

// argv[1] - サーバ番号を指定する
// argc[2] - 送信する文字列を入力する
int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3)
	{
		write(STDERR_FILENO, "Error: Invalid argument\n", 24);
		return (1);
	}
	pid = (pid_t)ft_atoi(argv[1]);
	if (exist_process(pid))
	{
		send_reset(pid);
		send_str(pid, argv[2]);
	}
	else
	{
		write(STDERR_FILENO, 
			"Error: The process ID does not exist or is not allowed to send signals.\n", 72);
		return(1);
	}
	return (0);
}