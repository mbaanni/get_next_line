/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaanni <mbaanni@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:56:23 by mbaanni           #+#    #+#             */
/*   Updated: 2022/11/06 08:52:01 by mbaanni          ###   ########.fr       */
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

char	*ft_strjoin(char *buf, char *str)
{
	char	*newline;
	int		i;
	int		j;

	i = 0;
	if (!buf)
	{
		buf = malloc(sizeof(char) * 1);
		if (!buf)
			return (0);
		*buf = 0;
	}
	newline = malloc(sizeof(char) * (ft_strlen(buf) + ft_strlen(str) + 1));
	if (!newline)
		return (0);
	while (buf[i])
	{
		newline[i] = buf[i];
		i++;
	}
	j = 0;
	while (str[j])
		newline[i++] = str[j++];
	newline[i] = 0;
	free (buf);
	return (newline);
}

int	ft_strchr(char *buf)
{
	int	i;

	i = 0;
	if (buf == 0)
		return (1);
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}
