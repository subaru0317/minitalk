/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:13:19 by smihata           #+#    #+#             */
/*   Updated: 2023/03/20 10:31:11 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t x, size_t y)
{
	if (x > y)
		return (y);
	return (x);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	s_len;
	size_t	dst_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len > start && len != 0)
		dst_len = ft_min(s_len - start, len);
	else
		dst_len = 0;
	dst = (char *)ft_calloc(dst_len + 1, sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s + start, dst_len + 1);
	return (dst);
}
