/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmouhib <bmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:45:44 by bmouhib           #+#    #+#             */
/*   Updated: 2024/07/08 19:30:51 by bmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return (1);
	return (0);
}

char	*ft_strcpy(char *str)
{
	int		i;
	char	*cpy;

	i = 0;
	if (!str || !*str)
		return (NULL);
	cpy = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	while (*str && *str != '\n')
		cpy[i++] = *str++;
	if (*str == '\n')
		cpy[i++] = '\n';
	cpy[i] = '\0';
	return (cpy);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	i += (s[i] == '\n');
	return (i);
}

char	*ft_strjoin(char *line, char *buffer)
{
	size_t	i;
	size_t	len;
	char	*s;

	len = ft_strlen(buffer) + ft_strlen(line);
	s = malloc((len + 1) * sizeof(char));
	if (!s)
		return (free(line), NULL);
	i = 0;
	if (line)
	{
		i--;
		while (line[++i])
			s[i] = line[i];
		free(line);
	}
	while (*buffer && *buffer != '\n')
		s[i++] = *buffer++;
	if (*buffer == '\n')
		s[i] = '\n';
	s[len] = '\0';
	return (s);
}
