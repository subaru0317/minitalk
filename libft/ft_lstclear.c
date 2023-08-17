/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:56:15 by smihata           #+#    #+#             */
/*   Updated: 2023/03/14 15:04:29 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*ndptr;

	if (!lst || !del)
		return ;
	ndptr = *lst;
	while (ndptr)
	{
		tmp = ndptr->next;
		ft_lstdelone(ndptr, del);
		ndptr = tmp;
	}
	*lst = NULL;
}
