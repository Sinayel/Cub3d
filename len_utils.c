/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judenis <judenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:43:02 by judenis           #+#    #+#             */
/*   Updated: 2025/03/10 14:36:04 by judenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

// returns the X lenght of the map
int	ft_lenline(char *filename) // nb est le numero de la ligne voulue
{
	int		i;
	char	buffer[4096];
	int		fd;
    int numero;

    numero = 0;
    i = 0;
	fd = open(filename, O_RDONLY);
	while (read(fd, buffer + i, 1) == 1)
	{
        numero++;
	}
	close(fd);
	return (0);
}

// returns the Y lenth of the map
int	ft_lastline(char *filename)
{
	int		i;
	int		compteur;
	char	buffer[4096];
	int		fd;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\nFichier de map invalide1\n", 32);
		close(fd);
		exit(1);
	}
	compteur = 1;
	while (read(fd, buffer + i, 1) == 1)
	{
		if (buffer[i] == '\n')
			compteur++;
		i++;
	}
	close(fd);
	return (compteur);
}

int	begining_of_map(char *filename)
{
	int		i;
	int		compteur;
	char	buffer[4096];
	int		fd;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\nFichier de map invalide2\n", 32);
		close(fd);
		exit(1);
	}
	compteur = 0;
	while (read(fd, buffer + i, 1) == 1)
	{
        while (buffer[i] != '1')
        {
		    if (buffer[i] == '\n')
                compteur++;
            i++;
        }
		i++;
	}
	close(fd);
	return (compteur);
}
