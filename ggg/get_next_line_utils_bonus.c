/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaanni <mbaanni@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:56:23 by mbaanni           #+#    #+#             */
/*   Updated: 2022/11/07 09:05:35 by mbaanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_calloc(int i, int size)
{
	char	*ptr;

	ptr = malloc(size * i);
	if (!ptr)
		return (0);
	*ptr = 0;
	return (ptr);
}

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
		buf = ft_calloc(1, sizeof(char));
	if (!buf)
		return (0);
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
	free(buf);
	return (newline);
}

int	ft_strchr(char *str)
{
	int	i;

	i = 0;
	if (str[0] == 0)
		return (1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}
