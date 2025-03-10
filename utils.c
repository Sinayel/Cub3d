/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judenis <judenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:22:31 by judenis           #+#    #+#             */
/*   Updated: 2025/03/10 15:23:11 by judenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int ft_close(int fd, int nbr)
{
	close(fd);
	return(nbr);
}

int ft_close_exit(t_vars *vars, char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_exit(vars);
}

int	ft_strchr_x(t_vars *vars, char searched_obj)
{
	int		i;
	int		compteur;
	char	buffer[4096];
	int		fd;

    (void)vars;
	i = 0;
	fd = open("map.cub", O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\nFichier de map invalide3\n", 32);
		exit(1);
	}
	compteur = 0;
	while (read(fd, buffer + i, 1) == 1)
	{
		if (buffer[i] == '\n' || buffer[i] == '\0')
			compteur = 0;
		if (buffer[i] == searched_obj)
			return (ft_close(fd, compteur));
		i++;
		compteur++;
	}
	close(fd);
	return (compteur);
}

int	ft_strchr_y(t_vars *vars, char searched_obj)
{
	int		i;
	int		j;
	int		compteur;
	char	buffer[4096];
	int		fd;

	i = 0;
	j = 0;
	fd = open(vars->filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\nFichier de map invalide4\n", 32);
		exit(1);
	}
	compteur = 0;
	while (read(fd, buffer + i, 1) == 1)
	{
		if (buffer[i] == '\n' || buffer[i] == '\0')
			j++;
		if (buffer[i] == searched_obj)
			return (ft_close(fd, j));
		i++;
	}
	close(fd);
	return (compteur);
}
