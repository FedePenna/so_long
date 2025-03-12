/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:53:37 by fepennar          #+#    #+#             */
/*   Updated: 2025/02/14 10:01:35 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char sep)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == sep)
			i++;
		if (str[i] != '\0')
		{
			count++;
			while (str[i] && str[i] != sep)
				i++;
		}
	}
	return (count);
}

char	**ft_split(char const *str, char sep)
{
	char	**astr;
	size_t	w_len;
	int		i;

	astr = (char **)malloc((count_words(str, sep) + 1) * sizeof(char *));
	if (!astr || !str)
		return (0);
	i = 0;
	while (*str)
	{
		while (*str == sep && *str)
			str++;
		if (*str)
		{
			if (ft_strchr(str, sep))
				w_len = ft_strchr(str, sep) - str;
			else
				w_len = ft_strlen(str);
			astr[i++] = ft_substr(str, 0, w_len);
			str += w_len;
		}
	}
	astr[i] = NULL;
	return (astr);
}

/*
int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <string> <separator>\n", argv[0]);
        return 1;
    }
        int     i = 0;
    const char *input = argv[1];
    char sep = argv[2][0]; // Usare il primo carattere di argv[2] come separatore

    char **result = ft_split(input, sep);
    if (!result)
    {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return 1;
    }

    printf("Split result:\n");
    while (result[i] != NULL)
    {
        printf("[%d]: '%s'\n", i, result[i]);
        free(result[i]); // Liberare ogni stringa allocata
        i++;
    }

    free(result); // Liberare l'array di puntatori

    return 0;
}

*/
