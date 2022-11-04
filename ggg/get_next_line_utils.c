/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaanni <mbaanni@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:56:23 by mbaanni           #+#    #+#             */
/*   Updated: 2022/11/04 16:03:02 by mbaanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *line, char *buf)
{
	char	*newline;
	int		i;
	int		j;

	i = 0;
	if (!line)
	{
		line = malloc(sizeof(char) * 1);
		*line = '\0';
	}
	if (!buf)
	{
		free(line);
		return (0);
	}
	newline = malloc(sizeof(char) * (ft_strlen(line) + ft_strlen(buf) + 1));
	if (!newline)
		return (0);
	while (line[i])
	{
		newline[i] = line[i];
		i++;
	}
	j = 0;
	while (buf[j])
		newline[i++] = buf[j++];
	newline[i] = 0;
	free(line);
	return (newline);
}

int	ft_strchr(char *buf)
{
	int	i;

	i = 0;
	if (!buf)
		return (1);
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}
