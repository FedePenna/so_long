/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:32:04 by fepennar          #+#    #+#             */
/*   Updated: 2024/12/16 09:51:45 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	mstr = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!mstr)
		return (NULL);
	while (s1[i])
	{
		mstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		mstr[i] = s2[j];
		i++;
		j++;
	}
	mstr[i] = '\0';
	return (mstr);
}
/*
int     main()
{
        char    str[] = "No vabbe puppame la";
        char    separatore[] = " fava, bimbo merda";
        printf("La stringa concatenata e %s", ft_strjoin(str, separatore));

}
*/
