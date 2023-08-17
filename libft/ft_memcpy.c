/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:30:12 by smihata           #+#    #+#             */
/*   Updated: 2023/03/19 15:33:58 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	void	*ptr;

	ptr = dst;
	if (dst == src)
		return (ptr);
	while (len--)
		*(unsigned char *)dst++ = *(const unsigned char *)src++;
	return (ptr);
}
