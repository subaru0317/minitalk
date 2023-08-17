/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:19:52 by smihata           #+#    #+#             */
/*   Updated: 2023/04/22 15:28:29 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static unsigned int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

// void	ft_putnbr_fd(int n, int fd)
// {
// 	unsigned int	plus_n;
// 	char			c[20];
// 	size_t			len;

// 	if (n < 0)
// 		ft_putchar_fd('-', fd);
// 	plus_n = ft_abs(n);
// 	len = 0;
// 	while (1)
// 	{
// 		c[len++] = plus_n % 10 + '0';
// 		plus_n /= 10;
// 		if (plus_n == 0)
// 			break ;
// 	}
// 	while (len--)
// 		ft_putchar_fd(c[len], fd);
// }

void	ft_putnbr_fd(long long n, int fd)
{
	unsigned long long	plus_n;
	char				c[20];
	size_t				len;

	if (n < 0)
		ft_putchar_fd('-', fd);
	plus_n = ft_abs(n);
	len = 0;
	while (1)
	{
		c[len++] = plus_n % 10 + '0';
		plus_n /= 10;
		if (plus_n == 0)
			break ;
	}
	while (len--)
		ft_putchar_fd(c[len], fd);
}
