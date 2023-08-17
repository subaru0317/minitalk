/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:00:53 by smihata           #+#    #+#             */
/*   Updated: 2023/03/20 13:50:22 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;
	size_t	big_len;

	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	big_len = ft_strlen(big);
	if (big_len < len)
		len = big_len;
	i = 0;
	little_len = ft_strlen(little);
	while (1)
	{
		if (little_len + i > len)
			return (NULL);
		if (!ft_strncmp(big + i, little, little_len))
			break ;
		i++;
	}
	return ((char *)(big + i));
}
