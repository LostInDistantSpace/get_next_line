/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmouhib <bmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:45:50 by bmouhib           #+#    #+#             */
/*   Updated: 2024/06/23 17:54:46 by bmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!*str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	i += (str[i] == '\n');
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (*str && *str != '\n')
		line[i++] = *str++;
	if (*str == '\n')
		line[i++] = *str;
	line[i] = '\0';
	return (line);
}

char	*ft_get_buffer(char *str)
{
	int		i;
	char	*line;
	char	*ptr;

	ptr = str;
	if (!str)
		return (NULL);
	while (*str && *str != '\n')
		str++;
	str += (*str == '\n');
	if (!*str)
	{
		free(ptr);
		return (NULL);
	}
	line = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (*str)
		line[i++] = *str++;
	line[i] = '\0';
	free(ptr);
	return (line);
}

char	*ft_read(int fd, char *line)
{
	int				read_bytes;
	char			*buff;

	if (ft_strchr(line, '\n'))
		return (line);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(line, '\n') && read_bytes)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (!read_bytes)
			return (free(buff), line);
		if (read_bytes < 0)
			return (free(line), free(buff), NULL);
		buff[read_bytes] = '\0';
		line = ft_strjoin(line, buff);
	}
	free(buff);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	str = ft_get_buffer(str);
	return (line);
}
