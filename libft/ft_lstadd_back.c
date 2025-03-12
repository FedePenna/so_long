/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:58:28 by fepennar          #+#    #+#             */
/*   Updated: 2024/12/17 16:52:37 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*act;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	act = *lst;
	while (act->next)
		act = act->next;
	act->next = new;
}
/*
int main()
{
        t_list *node1 = ft_lstnew("hello");
        t_list *node2 = ft_lstnew("bye");
	ft_lstadd_back(&node1, node2);
	printf("%s\n", (char *)ft_lstlast(node1)->content);
}
*/
