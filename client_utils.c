/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:18:18 by smihata           #+#    #+#             */
/*   Updated: 2023/08/21 15:30:28 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static unsigned long	ft_is_overflow(int sign)
{
	if (sign < 0)
		return (INT_MIN);
	else
		return (INT_MAX);
}

static int	ft_has_sign(char c)
{
	if (c == '-')
		return (-1);
	else
		return (1);
}

static int	value_is_overflow(unsigned int value, int num, int sign)
{
	unsigned int	cutoff;
	unsigned int	cutlim;
	unsigned int	boarder;

	boarder = ft_is_overflow(sign);
	cutlim = boarder % 10;
	cutoff = boarder / 10;
	if (value > boarder || (value == cutoff && (unsigned int)num > cutlim))
		return (1);
	else
		return (0);
}

static int	is_ok(size_t nptr_len, int sign, char *nptr)
{
	unsigned int	value;
	size_t			i;
	int				num;

	value = 0;
	i = 0;
	while (i < nptr_len)
	{
		num = *nptr++ - '0';
		if (!(0 <= num && num <= 9))
			return (0);
		value = value * 10 + num;
		if (value_is_overflow(value, num, sign))
			return (0);
		i++;
	}
	return (1);
}

int	is_int(char *nptr)
{
	int				sign;
	size_t			nptr_len;

	sign = ft_has_sign(*nptr);
	nptr_len = ft_strlen(nptr);
	if (*nptr == '+' || *nptr == '-')
	{
		nptr_len--;
		nptr++;
	}
	if (nptr_len == 0)
		return (0);
	if (is_ok(nptr_len, sign, nptr))
		return (1);
	return (0);
}
