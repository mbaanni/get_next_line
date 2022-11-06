/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaanni <mbaanni@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 09:55:03 by mbaanni           #+#    #+#             */
/*   Updated: 2022/11/06 18:21:45 by mbaanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	line = 0;
	if (fd < 0 || BUFFER_SIZE == 0)
		return (0);
	line = read_line(fd, buf);
	if (line == 0)
		return (0);
	buf = to_keep(line);
	line = to_ret(line);
	return (line);
}

char	*read_line(int fd, char *buf)
{
	char	str[BUFFER_SIZE + 1];
	int		i;

	i = 1;
	str[0] = 0;
	while (i && ft_strchr(str))
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i < 0)
		{
			i = 0;
			if (buf)
			{
				while (buf[i])
				{
					buf[i] = 0;
					i++;
				}
			}
			return (0);
		}
		str[i] = 0;
		buf = ft_strjoin(buf, str, 1);
	}
	return (buf);
}

int	lent(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

char	*to_ret(char *line)
{
	char	*newline;
	int		i;

	i = lent(line);
	if (line[i] == '\n')
		i++;
	if (i == 0)
		free (line);
	if (i == 0)
		return (0);
	newline = (char *)malloc(sizeof(char) * (i + 1));
	if (!newline)
		return (0);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		newline[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		newline[i++] = '\n';
	newline[i] = 0;
	free(line);
	return (newline);
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

// #include<stdio.h>
// int main()
// {
// 	int fd = open("file", O_CREAT |O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	return (0);
// }
