/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaanni <mbaanni@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:22:06 by mbaanni           #+#    #+#             */
/*   Updated: 2022/11/04 09:42:08 by mbaanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

char *get_next_line(int fd);
int	ft_strlen(char *str);
int	ft_strchr(char *buf);
char	*ft_strjoin(char *s1, char *s2);

#endif