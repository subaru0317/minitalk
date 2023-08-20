/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 09:10:48 by smihata           #+#    #+#             */
/*   Updated: 2023/08/20 15:23:16 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

volatile sig_atomic_t	g_char = 0;

void	signal_handler(int signum, siginfo_t *info, void *dummy)
{
	static int	i;
	char		c;

	g_char <<= 1;
	if (signum == SIGUSR1)
		g_char |= 1;
	else if (signum == SIGUSR2)
		;
	i++;
	c = 0xff & g_char;
	if (i == 8)
	{
		write(STDOUT_FILENO, &c, 1);
		i = 0;
	}
}

// sig      :   handlerの呼び出しを引き起こしたsignalの番号
// info     :   siginfo_tへのポインタ。signalに関する詳細情報を含む構造体
// ucontext :   ucontext_t構造体へのポインタ。void*にキャストされている。
//              カーネルによってユーザ空間スタックに保存されたsignalコンテキスト情報が含まれる

static void	ft_error()
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
	error = sigemptyset(&act2.sa_mask);
	if (error == -1)
		ft_error();
	sigaddset(&act2.sa_mask, SIGUSR1);
	act1.sa_sigaction = signal_handler;
	act2.sa_sigaction = signal_handler;
	act1.sa_flags = SA_SIGINFO;
	act2.sa_flags = SA_SIGINFO;
	printf("server pid=%d\n", getpid()); // ft_printfに要修正
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
