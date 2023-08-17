/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:57:03 by smihata           #+#    #+#             */
/*   Updated: 2023/03/20 13:46:51 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (*(unsigned char *)(b1 + i) != *(unsigned char *)(b2 + i))
			return (*(unsigned char *)(b1 + i) - *(unsigned char *)(b2 + i));
		i++;
	}
	return (0);
}
