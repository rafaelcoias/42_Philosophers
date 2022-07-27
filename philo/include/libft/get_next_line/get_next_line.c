/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:16:31 by rade-sar          #+#    #+#             */
/*   Updated: 2021/11/17 20:42:26 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strcat(char *dest, char *src)
{
	size_t	id;
	size_t	is;
	char	*new;

	if (!dest)
	{
		dest = malloc(sizeof(char));
		dest[0] = '\0';
	}
	if (!dest || !src)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(dest) + ft_strlen(src) + 1));
	if (!new)
		return (NULL);
	id = -1;
	is = 0;
	if (dest)
		while (dest[++id] != '\0')
			new[id] = dest[id];
	while (src[is] != '\0')
		new[id++] = src[is++];
	new[id] = '\0';
	free(dest);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	char		*nl;
	int			res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	res = BUFFER_SIZE;
	while (!ft_strchr(save, '\n') && res != 0)
	{
		res = read(fd, line, BUFFER_SIZE);
		if (res < 0)
		{
			free(line);
			return (NULL);
		}
		line[res] = '\0';
		save = ft_strcat(save, line);
	}
	free(line);
	nl = ft_find_nl(save);
	save = ft_new_save(save);
	return (nl);
}
