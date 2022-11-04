/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaanni <mbaanni@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:40:36 by mbaanni           #+#    #+#             */
/*   Updated: 2022/11/04 09:44:14 by mbaanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *buf)
{
	int	i;

	i = 0;
	if (!buf)
		return(1);
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}


char	*ft_strjoin(char *s1, char *s2)
{
	char	*line;
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (0);
		*s1 = '\0';
	}
	if (!s2)
	{
		free(s1);
		return (0);
	}
	line = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!line)
		return (0);
	while (s1[i])
	{
		line[i] = s1[i];
		i++;
	}
	while (s2[j])
		line[i++] = s2[j++];
	line[i] = '\0';
	free (s1);
	return (line);
}
