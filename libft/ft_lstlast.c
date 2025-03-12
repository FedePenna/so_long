/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:06:04 by fepennar          #+#    #+#             */
/*   Updated: 2024/12/18 15:21:13 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
int main()
{
	t_list *new = ft_lstnew("hello");
	new->next = ft_lstnew("world");
	new->next->next = ft_lstnew("42");

	t_list *new1 = ft_lstlast(new);
	printf("%s\n", (char *)(new1)->content);
}*/
