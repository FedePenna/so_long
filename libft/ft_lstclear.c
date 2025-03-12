/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:58:37 by fepennar          #+#    #+#             */
/*   Updated: 2024/12/18 14:22:21 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*first;
	t_list	*nextnode;

	if (!lst || !del)
		return ;
	first = *lst;
	while (first)
	{
		nextnode = first->next;
		del(first->content);
		free(first);
		first = nextnode;
	}
	*lst = NULL;
}
