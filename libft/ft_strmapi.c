/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:35:24 by fepennar          #+#    #+#             */
/*   Updated: 2024/12/16 12:18:34 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				len;
	unsigned int	i;
	char			*istr;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	istr = (char *)malloc(sizeof(char) * (len + 1));
	if (!istr)
		return (NULL);
	while (s[i])
	{
		istr[i] = f(i, s[i]);
		i++;
	}
	istr[i] = '\0';
	return (istr);
}
