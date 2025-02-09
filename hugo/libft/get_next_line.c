/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:29:23 by cauvray           #+#    #+#             */
/*   Updated: 2024/12/12 00:09:41 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_remainder(char *buffer)
{
	int		i;
	int		j;
	char	*remainder;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i] || !buffer[i + 1])
	{
		free(buffer);
		return (NULL);
	}
	remainder = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!remainder)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		remainder[j++] = buffer[i++];
	free(buffer);
	return (remainder);
}

static char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer || !buffer[0])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n' )
		line = ft_calloc(i + 2, sizeof(char));
	else
		line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*read_and_append(int fd, char *all, char *buffer, int *byte_read)
{
	char	*temp;

	while (*byte_read > 0)
	{
		buffer[*byte_read] = '\0';
		temp = ft_strjoin(all, buffer);
		free(all);
		all = temp;
		if (!all)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
		*byte_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (all);
}

static char	*read_file(int fd, char *all)
{
	char	*buffer;
	int		byte_read;

	if (!all)
		all = ft_calloc(1, 1);
	if (!all)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
	{
		free(all);
		return (NULL);
	}
	byte_read = read(fd, buffer, BUFFER_SIZE);
	all = read_and_append(fd, all, buffer, &byte_read);
	free(buffer);
	if (byte_read < 0)
	{
		free(all);
		return (NULL);
	}
	return (all);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_get_remainder(buffer);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		i;

// 	i = 0;
// 	fd = open("multiple_nl.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
