/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmouhib <bmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:45:50 by bmouhib           #+#    #+#             */
/*   Updated: 2024/07/05 18:05:05 by bmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_rectify(char *buff)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(buff);
	if (!buff[i])
		buff[0] = '\0';
	else
	{
		while (buff[i])
			buff[j++] = buff[i++];
		buff[j] = '\0';
	}
}

char	*ft_read(int fd, char *line, char *buffer)
{
	int		read_bytes;
	int		new_line;

	read_bytes = 1;
	new_line = ft_strchr(line, '\n');
	while (!new_line && read_bytes)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (!read_bytes)
			return (line);
		if (read_bytes < 0)
			return (free(line), NULL);
		buffer[read_bytes] = '\0';
		new_line = ft_strchr(buffer, '\n');
		line = ft_strjoin(line, buffer);
		ft_rectify(buffer);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strcpy(buffer);
	ft_rectify(buffer);
	line = ft_read(fd, line, buffer);
	if (!line)
		return (NULL);
	return (line);
}
