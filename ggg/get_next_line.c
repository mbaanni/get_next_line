/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaanni <mbaanni@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:58:46 by mbaanni           #+#    #+#             */
/*   Updated: 2022/11/04 19:58:18 by mbaanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *line)
{
	char	buf[BUFFER_SIZE + 1];
	int		i;

	i = 1;
	while (i && ft_strchr(buf))
	{
		i = read(fd, buf, BUFFER_SIZE);
		buf[i] = 0;
		if (!buf[0] && !line)
			return (0);
		line = ft_strjoin(line, buf);
		if (!line)
			return (0);
	}
	return (line);
}

char	*to_ret(char *line)
{
	char	*newline;
	int		i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	newline = (char *)malloc(sizeof(char) * (i + 2));
	i = 0;
	while (line[i])
	{
		newline[i] = line[i];
		if (line[i] == '\n')
			break ;
		i++;
	}
	i++;
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
	if (i == j)
		return (0);
	buf = malloc(sizeof(char) * (j - i + 1));
	if (!buf)
		return (0);
	j = 0;
	i++;
	while (line[i])
		buf[j++] = line[i++];
	buf[j] = 0;
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || read(fd, buf, 0) < 0 || BUFFER_SIZE == 0)
		return (0);
	line = read_line(fd, buf);
	if (!line)
		return (0);
	buf = to_keep(line);
	line = to_ret(line);
	return (line);
}

// #include<stdio.h>

// int main()
// {
// 	int fd = open("file", O_RDONLY);

// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	return (0);
// }