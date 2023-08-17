/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:30:39 by smihata           #+#    #+#             */
/*   Updated: 2023/03/20 12:52:24 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cnt_substr_size(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	ft_cnt_c(char const *s, char c, size_t i)
{
	size_t	cnt;

	cnt = 0;
	while (s[i] == c)
	{
		cnt++;
		i++;
	}
	return (cnt);
}

static size_t	ft_cnt_substr(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		s += ft_cnt_substr_size(s, c);
		cnt++;
	}
	return (cnt);
}

static void	*ft_arr_clear(char **arr, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;
	size_t	num_substr;
	size_t	substr_size;

	if (!s)
		return (NULL);
	num_substr = ft_cnt_substr(s, c);
	arr = (char **)ft_calloc(num_substr + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (j < num_substr)
	{
		i += ft_cnt_c(s, c, i);
		substr_size = ft_cnt_substr_size(s + i, c);
		arr[j] = ft_substr(s, i, substr_size);
		if (!arr[j])
			return (ft_arr_clear(arr, j));
		i += substr_size;
		j++;
	}
	return (arr);
}
