/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 09:10:44 by smihata           #+#    #+#             */
/*   Updated: 2023/08/19 17:55:29 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

void	ft_error()
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(0);
}

void	send_char(pid_t pid, char c)
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

void	send_str(pid_t pid, char *s)
{
	while (*s)
	{
		send_char(pid, *s);
		s++;
	}
}

void	send_reset(pid_t pid)
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
		usleep(100);
	}
}

// argv[1] - サーバ番号を指定する
// argc[2] - 送信する文字列を入力する
int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3)
		return (1);
	pid = (pid_t)ft_atoi(argv[1]);
	send_reset(pid);
	send_str(pid, argv[2]);
	return (0);
}