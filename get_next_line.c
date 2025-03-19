/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judenis <judenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:29:03 by judenis           #+#    #+#             */
/*   Updated: 2025/03/10 11:21:35 by judenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static char	*ft_strchr_gnl(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}

static char	*set_line(char *line_buffer)
{
	char	*truc_qui_reste;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == 0 || line_buffer[1] == 0)
		return (NULL);
	truc_qui_reste = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*truc_qui_reste == 0)
	{
		free(truc_qui_reste);
		truc_qui_reste = NULL;
	}
	line_buffer[i + 1] = 0;
	return (truc_qui_reste);
}

static char	*fill_line_buffer(int fd, char *truc_qui_reste, char *buffer)
{
	ssize_t	read_status;
	char	*tmp;

	read_status = 1;
	while (read_status > 0)
	{
		read_status = read(fd, buffer, BUFFER_SIZE);
		if (read_status == -1)
		{
			free(truc_qui_reste);
			return (NULL);
		}
		else if (read_status == 0)
			break ;
		buffer[read_status] = 0;
		if (!truc_qui_reste)
			truc_qui_reste = ft_strdup("");
		tmp = truc_qui_reste;
		truc_qui_reste = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr_gnl(buffer, '\n'))
			break ;
	}
	return (truc_qui_reste);
}

char	*get_next_line(int fd)
{
	static char	*truc_qui_reste;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
	{
		free(truc_qui_reste);
		free(buffer);
		truc_qui_reste = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = fill_line_buffer(fd, truc_qui_reste, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	truc_qui_reste = set_line(line);
	return (line);
}

// int	main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("test", O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		printf("%s", line);
// 		free(line);
// 		line = NULL;
// 	}
// }