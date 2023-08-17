/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:03:14 by smihata           #+#    #+#             */
/*   Updated: 2023/03/26 18:13:14 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// set が NULL のときにNULLを返すようにしているが、本当はs1を返すべきかも
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	i;
	size_t	front;
	size_t	back;

	if (!s1 || !set)
		return (NULL);
	if (*s1 == '\0' || *set == '\0')
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	i = 0;
	front = 0;
	while (i < s1_len && ft_strchr(set, s1[i]))
	{
		front++;
		i++;
	}
	i = s1_len - 1;
	back = 0;
	while (i > 0 && ft_strrchr(set, s1[i]))
	{
		back++;
		i--;
	}
	return (ft_substr(s1, front, s1_len - front - back));
}
