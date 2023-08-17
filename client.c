/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 09:10:44 by smihata           #+#    #+#             */
/*   Updated: 2023/05/06 10:06:40 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

void	send_char(pid_t, pid, char c)
{
	int	bits;

	bits = 8;
}

void	send_str(pid_t pid, char *s)
{
	while (*s)
	{
		send_char(pid, *s);
		s++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3)
		return (1);
	pid = (pid_t)ft_atoi(argv[1]);
	send_str(argv[2]);
	return (0);
}