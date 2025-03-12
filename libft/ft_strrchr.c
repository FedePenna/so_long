/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:58:01 by fepennar          #+#    #+#             */
/*   Updated: 2024/12/18 18:31:54 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*str;
	char		*last;

	str = s;
	last = NULL;
	while (*s)
		s++;
	if ((char)c == '\0')
		return ((char *)s);
	while (s-- > str)
	{
		if (*s == (char)c)
			return (last = (char *)s);
	}
	return (last);
}

/*
int	main()
{
	printf("%s\n", ft_strrchr("uccidetemioamonapol", 'i'));
}
*/
