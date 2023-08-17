/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:38:15 by smihata           #+#    #+#             */
/*   Updated: 2023/03/20 10:33:34 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*ptr;

	ptr = dst;
	if (dst < src)
	{
		while (len--)
			*(unsigned char *)dst++ = *(const unsigned char *)src++;
	}
	else if (dst > src)
	{
		dst += len - 1;
		src += len - 1;
		while (len--)
			*(unsigned char *)dst-- = *(const unsigned char *)src--;
	}
	return (ptr);
}
