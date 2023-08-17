/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:22:55 by smihata           #+#    #+#             */
/*   Updated: 2023/03/19 16:51:29 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_num_len(int n)
{
	size_t			len;
	unsigned int	plus_n;

	len = 0;
	if (n < 0)
	{
		plus_n = n * -1;
		len++;
	}
	else
		plus_n = n;
	while (1)
	{
		len++;
		plus_n /= 10;
		if (plus_n == 0)
			break ;
	}
	return (len);
}

static unsigned int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

char	*ft_itoa(int n)
{
	char			*str;
	size_t			i;
	unsigned int	plus_n;

	str = (char *)ft_calloc(ft_num_len(n) + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	plus_n = ft_abs(n);
	i = ft_num_len(n) - 1;
	while (1)
	{
		if (i == 0 && n < 0)
			break ;
		str[i] = plus_n % 10 + '0';
		if (i == 0 && n >= 0)
			break ;
		plus_n /= 10;
		i--;
	}
	return (str);
}
