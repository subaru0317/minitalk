/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 09:10:48 by smihata           #+#    #+#             */
/*   Updated: 2023/12/01 13:04:29 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_char = 0;

static void	signal_handler(int signum, siginfo_t *info, void *dummy)
{
	static int	i;
	char		c;

	(void)info;
	(void)dummy;
	g_char <<= 1;
	if (signum == SIGUSR1)
		g_char |= 1;
	else if (signum == SIGUSR2)
		;
	i++;
	c = g_char;
	if (i == 8)
	{
		write(STDOUT_FILENO, &c, 1);
		i = 0;
		g_char = 0;
	}
}

static void	ft_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(1);
}

static void	ft_stdout_pid(void)
{
	write(STDOUT_FILENO, "server pid=", 11);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	write(STDOUT_FILENO, "\n", 1);
}

int	main(void)
{
	struct sigaction	act1;
	struct sigaction	act2;

	if (sigemptyset(&act1.sa_mask) == -1)
		ft_error();
	sigaddset(&act1.sa_mask, SIGUSR2);
	if (sigemptyset(&act2.sa_mask) == -1)
		ft_error();
	sigaddset(&act2.sa_mask, SIGUSR1);
	act1.sa_sigaction = signal_handler;
	act2.sa_sigaction = signal_handler;
	act1.sa_flags = SA_SIGINFO;
	act2.sa_flags = SA_SIGINFO;
	ft_stdout_pid();
	if (sigaction(SIGUSR1, &act1, NULL) == -1)
		ft_error();
	if (sigaction(SIGUSR2, &act2, NULL) == -1)
		ft_error();
	while (1)
		pause();
	return (0);
}
