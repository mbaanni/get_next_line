/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaanni <mbaanni@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 09:55:03 by mbaanni           #+#    #+#             */
/*   Updated: 2022/11/07 18:24:48 by mbaanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	int			i;

	i = 0;
	line = read_line(fd, buf);
	if (line == 0)
		return (0);
	buf = to_keep(line);
	if (line[i] == 0)
	{
		free(line);
		return (0);
	}
	while (line[i])
	{
		if (line[i] == '\n')
		{
			if (line[i + 1])
				line[i + 1] = 0;
		}
		i++;
	}
	return (line);
}

char	*read_line(int fd, char *buf)
{
	char	str[BUFFER_SIZE + 1];
	int		i;

	i = 1;
	*str = 0;
	while (i && ft_strchr(str))
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i < 0)
		{
			i = 0;
			if (buf != 0)
				while (buf[i])
					buf[i++] = 0;
			return (0);
		}
		str[i] = 0;
		buf = ft_strjoin(buf, str);
	}
	return (buf);
}

char	*to_keep(char *line)
{
	char	*buf;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(line);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	if (i == j)
		return (0);
	buf = malloc(sizeof(char) * (j - i + 1));
	if (!buf)
		return (0);
	j = 0;
	while (line[i])
		buf[j++] = line[i++];
	buf[j] = 0;
	return (buf);
}
