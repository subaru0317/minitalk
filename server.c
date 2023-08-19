/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 09:10:48 by smihata           #+#    #+#             */
/*   Updated: 2023/08/19 18:04:01 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

volatile sig_atomic_t	g_char = 0;

// void	signal_handler(int signum, siginfo_t *info, void *dummy)
// {
// 	static int	i;
// 	static int	consecutive_SIGUSR2;
// 	char		c;

// 	g_char <<= 1;
// 	if (signum == SIGUSR1)
// 	{
// 		g_char |= 1;
// 		consecutive_SIGUSR2 = 0;
// 	}
// 	else if (signum == SIGUSR2)
// 	{
// 		consecutive_SIGUSR2++;
// 		if (consecutive_SIGUSR2 == 8)
// 		{
// 			i = 0;
// 			consecutive_SIGUSR2 = 0;
// 			return ;
// 		}
// 	}
// 	i++;
// 	c = 0xff & g_char;
// 	if (i == 8)
// 	{
// 		if (c == 0x00)
// 			g_char = 0;
// 		write(STDOUT_FILENO, &c, 1);
// 		i = 0;
// 	}
// }

void signal_handler(int signum, siginfo_t *info, void *dummy)
{
    static int consecutive_SIGUSR2 = 0;
    static int i;
    char c;

    if (signum == SIGUSR2)
    {
        consecutive_SIGUSR2++;
        if (consecutive_SIGUSR2 == 8)
        {
            i = 0;
            g_char = 0;  // こちらもリセットします
            consecutive_SIGUSR2 = 0;
            return;
        }
    }
    else
    {
        consecutive_SIGUSR2 = 0;
    }

    g_char <<= 1;
    if (signum == SIGUSR1)
        g_char |= 1;

    i++;
    c = 0xff & g_char;
    if (i == 8)
    {
        if (consecutive_SIGUSR2 < 8)
        {
            write(STDOUT_FILENO, &c, 1);
        }
        i = 0;
    }
}



void	ft_error()
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(0);
}

int main(void)
{
	struct sigaction act1;
	struct sigaction act2;
	int error;

	error = sigemptyset(&act1.sa_mask);
	if (error == -1)
		ft_error();
	sigaddset(&act1.sa_mask, SIGUSR2);
	sigaddset(&act1.sa_mask, SIGINT);
	error = sigemptyset(&act2.sa_mask);
	if (error == -1)
		ft_error();
	sigaddset(&act2.sa_mask, SIGUSR1);
	sigaddset(&act2.sa_mask, SIGINT);
	act1.sa_sigaction = signal_handler;
	act2.sa_sigaction = signal_handler;
	act1.sa_flags = SA_SIGINFO;
	act2.sa_flags = SA_SIGINFO;
	printf("server pid=%d\n", getpid());
	error = sigaction(SIGUSR1, &act1, NULL);
	if (error == -1)
		ft_error();
	error = sigaction(SIGUSR2, &act2, NULL);
	if (error == -1)
		ft_error();
	while (1)
		pause();
	return (0);
}