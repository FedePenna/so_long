/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:16:55 by fepennar          #+#    #+#             */
/*   Updated: 2024/12/16 10:11:58 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dest;

	i = 0;
	while (s[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	dest[i] = '\0';
	while (i--)
		dest[i] = s[i];
	return (dest);
}
/*
int	main (int ac, char **av)
{
	if (ac == 2)
	{
		ft_strdup(av[1]);
		printf("%s", av[1]);
	}
	else
		return (0);
}
*/
