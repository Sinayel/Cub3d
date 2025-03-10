/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judenis <judenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:31:08 by judenis           #+#    #+#             */
/*   Updated: 2025/03/10 15:23:55 by judenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void free_tabtab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

void print_tab(char **tab)
{
    int i = 0;
    while (tab[i])
    {
        printf("%s", tab[i]);
        i++;
    }
}

int launch(t_vars *vars)
{
    vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1920, 1080,
			"cub3D");
    vars->img_minimap_p = mlx_xpm_file_to_image(vars->mlx, "sprites/player.xpm", &vars->height , &vars->width);
    vars->img_minimap_w = mlx_xpm_file_to_image(vars->mlx, "sprites/wall.xpm", &vars->height , &vars->width);
    vars->img_minimap_f = mlx_xpm_file_to_image(vars->mlx, "sprites/floor.xpm", &vars->height , &vars->width);
    ft_minimap(vars);
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
    {
        ft_close_exit()
    } //! Mettre vraie securite
    i = 0;
    line = NULL;
    vars->map = (char **)malloc(sizeof(char *) * (vars->len_y + 1));
    
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        vars->map[i] = ft_strdup(line);
        i++;
        free(line);
        line = NULL;
    }
    vars->map[i] = NULL;
    close(fd);
}

int copy_map(char *path, t_vars *vars)
{
    vars->len_y = ft_lastline(path);
    copy(path, vars);
    print_tab(vars->map);
    return (0); // A changer
}

void vars_init(t_vars *vars, char *path)
{
    vars->filename = path;
    vars->facing = 0; // A changer une fois qu'une map sera lue
    vars->x = ft_strchr_x(vars, 'N') * 10;
    vars->y = ft_strchr_y(vars, 'N') * 10;
    vars->NO = NULL;
    vars->EA = NULL;
    vars->SO = NULL;
    vars->WE = NULL;
}

int main(int argc, char *argv[])
{
    t_vars vars;
    vars_init(&vars, argv[1]);
    (void)argc;
    // Parsing
    printf("FILENAME : %s\n", vars.filename);
    copy_map(argv[1], &vars);
    
    launch(&vars);
}