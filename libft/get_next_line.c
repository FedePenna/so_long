/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:20:13 by fepennar          #+#    #+#             */
/*   Updated: 2025/01/22 18:46:52 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 9
#endif

#include "libft.h"

static void	ft_bejoin(char **save, char *bstr)
{
	char	*savefile;

	if (*save)
	{
		savefile = *save;
		*save = ft_strjoin(*save, bstr);
		free(savefile);
	}
	else
		*save = ft_strdup(bstr);
}

static char	*ft_bnl(char **save, char *bstr)
{
	char	*position;
	char	*pre;
	char	*rstr;
	char	*tmp;

	position = ft_strchr(bstr, '\n');
	pre = ft_substr(bstr, 0, position - bstr + 1);
	if (*save)
	{
		rstr = ft_strjoin(*save, pre);
		tmp = *save;
		*save = ft_strdup(position + 1);
		free(tmp);
		free(pre);
	}
	else
	{
		rstr = pre;
		tmp = *save;
		*save = ft_strdup(position + 1);
		free(tmp);
	}
	free(bstr);
	return (rstr);
}

static char	*ft_no_bytces(char **save, char *bstr, ssize_t bytes_read)
{
	char	*end;

	if (bytes_read == 0)
	{
		if (*save && **save)
		{
			free(bstr);
			end = *save;
			*save = NULL;
			return (end);
		}
		free(bstr);
		free(*save);
		*save = NULL;
		return (NULL);
	}
	if (bytes_read < 0)
	{
		free(bstr);
		free(*save);
		*save = NULL;
		return (NULL);
	}
	return (NULL);
}

static char	*ft_snl(char **save, char *bstr)
{
	char	*position;
	char	*tmp;
	char	*rstr;

	position = ft_strchr(*save, '\n');
	rstr = ft_substr(*save, 0, position - *save + 1);
	free(bstr);
	tmp = *save;
	*save = ft_strdup(position + 1);
	free(tmp);
	return (rstr);
}

char	*get_next_line(int fd)
{
	char		*bstr;
	ssize_t		bytes;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bstr = (char *)malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!bstr)
		return (NULL);
	while (1)
	{
		if (save && ft_strchr(save, '\n'))
			return (ft_snl(&save, bstr));
		bytes = read(fd, bstr, BUFFER_SIZE);
		if (bytes <= 0)
			return (ft_no_bytces(&save, bstr, bytes));
		bstr[bytes] = '\0';
		if (ft_strchr(bstr, '\n'))
			return (ft_bnl(&save, bstr));
		ft_bejoin(&save, bstr);
	}
	return (NULL);
}
/*
int     main()
{
        int     fd = open("test", O_RDONLY);
        //printf("%s", get_next_line(fd));

        char *str = get_next_line(fd);
        while (str != NULL)
        {
                printf("%s", str);
                free(str);
                str = get_next_line(fd);
        }
        return (0);
}
*/
