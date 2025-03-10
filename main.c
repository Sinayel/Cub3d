/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judenis <judenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:31:08 by judenis           #+#    #+#             */
/*   Updated: 2025/03/10 13:20:15 by judenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void print_tab(char **tab)
{
    int i = 0;
    while (tab[i])
    {
        printf("%s\n", tab[i]);
        i++;
    }
}

int launch(t_vars *vars)
{
    vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1920, 1080,
			"cub3D");
    mlx_hook(vars->win, 2, (1L << 0), keyhook, vars);
	mlx_hook(vars->win, 17, 0, ft_exit, vars);
    mlx_loop(vars->mlx);
    return (0);
}

// int allocate_tab(t_vars *vars, char *path)
// {
//     int i;

//     i = 0;
//     vars->map = (char **)malloc(sizeof(char *) * (vars->len_y));
//     if (!vars->map)
//         return (1);
//     while (i < vars->len_y)
//     {
//         vars->map[i] = (char *)malloc(sizeof(char) * vars->len_x + 1);
//         if (!vars->map[i])
//             return (2);
//         i++;
//     }
//     return (0);
// }

void write_map(t_vars *vars, int begining, int fd)
{
    char	*buffer;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = begining;
	buffer = (char *)malloc(sizeof(char) * 4069);
	// if (!buffer)
	// 	return (NULL); // a voir
	while (i < vars->len_y)
	{
		j = 0;
		while (read(fd, buffer + k, 1) == 1)
		{
			if (buffer[k] == '\n' || buffer[k] == '\0')
				break ;
            vars->map[i][j] = buffer[k];
			j++;
		}
		vars->map[i][j] = '\0';
		i++;
	}
	free(buffer);
}

void copy(char *path, t_vars *vars)
{
    char *line;
    int i;
    int fd;

    fd = open(path, O_RDONLY);
    if (fd == -1)
        return; //! Mettre vraie securite
    i = 0;
    line = NULL;
    vars->map = (char **)malloc(sizeof(char *) * (vars->len_y));
    
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        vars->map[i] = line;
        i++;
        free(line);
        line = NULL;
    }
    close(fd);
}

int copy_map(char *path, t_vars *vars)
{
    int begining;
    // int fd;

    begining = begining_of_map(path);
    // vars->len_x = ft_lenline(path);
    vars->len_y = ft_lastline(path);
    // allocate_tab(vars, path); // if == 1 exit / if == 2 free and exit
    // fd = open(path, O_RDONLY);
    // write_map(vars, begining, fd);
    copy(path, vars);
    print_tab(vars->map);
    return (0); // A changer
}

void vars_init(t_vars *vars)
{
    vars->facing = 0; // A changer une fois qu'une map sera lue
    vars->x = 0;
    vars->y = 0;
    vars->NO = NULL;
    vars->EA = NULL;
    vars->SO = NULL;
    vars->WE = NULL;
}

int main(int argc, char *argv[])
{
    t_vars vars;
    vars_init(&vars);
    (void)argc;
    // Parsing
    copy_map(argv[1], &vars);
    
    launch(&vars);
    
}