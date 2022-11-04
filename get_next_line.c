/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaanni <mbaanni@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:21:46 by mbaanni           #+#    #+#             */
/*   Updated: 2022/11/04 09:44:20 by mbaanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*get_rest(char *buf)
{
	char	*rest;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(buf);
	if (i == 0)
		return (0);
	while (buf[j] && buf[j] != '\n')
		j++;
	j++;
	if (j == i)
		return (0);
	//j++;
	rest = malloc(sizeof(char) * (i - j) + 1);
	if (!rest)
		return (0);
	i = 0;
	while(buf[j])
	{
		rest[i] = buf[j];
		i++;
		j++;
	}
	rest[i] = 0;
	return (rest);
}

char	*extract(char *line)
{
	char	*ret;
	int	i;

	i = 0;
	while(line[i] != '\n' && line[i])
		i++;
	ret = malloc(sizeof(char) * (i + 2));
	if (!ret)
		return (0);
	i = 0;
	while (line[i])
	{
		ret[i] = line[i];
		if (line[i] == '\n')
			break;
		i++;
	}
	i++;
	ret[i] = '\0';
	return (ret);
}

char	*read_line(int fd, char *buf, char *line)
{
	int	i;

	i = 1;
	while (i && ft_strchr(buf))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i <= 0)
			break;
		buf[i] = 0;
		line = ft_strjoin(line, buf);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE];
	static char	*line;
	char		*to_ret;

	if (BUFFER_SIZE == 0 || fd < 0 || read(fd, buf, 0) < 0)
		return (0);
	line = read_line(fd, buf, line);
	if (!line)
		return (0);
	to_ret = extract(line);
	free (line);
	//line = get_rest(buf);
	return (to_ret);
}
#include<stdio.h>

int main()
{
	int fd = open("file", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
