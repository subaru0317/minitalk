/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:27:39 by smihata           #+#    #+#             */
/*   Updated: 2023/03/26 17:46:28 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_isspace(unsigned char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static unsigned long	ft_is_overflow_or_underflow(int sign)
{
	if (sign < 0)
		return (LONG_MIN);
	else
		return (LONG_MAX);
}

static int	ft_has_sign(char c)
{
	if (c == '-')
		return (-1);
	else
		return (1);
}

int	ft_atoi(const char *nptr)
{
	int				sign;
	int				cutlim;
	unsigned long	cutoff;
	unsigned long	value;
	int				num;

	while (ft_isspace((unsigned char)(*nptr)))
		nptr++;
	sign = ft_has_sign(*nptr);
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	cutoff = ft_is_overflow_or_underflow(sign);
	cutlim = cutoff % 10;
	cutoff /= 10;
	value = 0;
	while (1)
	{
		num = *nptr++ - '0';
		if (!(0 <= num && num <= 9))
			break ;
		if (value > cutoff || (value == cutoff && num > cutlim))
			return ((int)ft_is_overflow_or_underflow(sign));
		value = value * 10 + num;
	}
	return ((int)(sign * value));
}
