/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylouvel <ylouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:31:08 by judenis           #+#    #+#             */
/*   Updated: 2025/03/10 19:22:45 by ylouvel          ###   ########.fr       */
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
    t_img img;
    vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1920, 1080,
			"cub3D");


    vars->img_minimap_p = mlx_xpm_file_to_image(vars->mlx, "sprites/player.xpm", &vars->height , &vars->width);
    vars->img_minimap_w = mlx_xpm_file_to_image(vars->mlx, "sprites/wall.xpm", &vars->height , &vars->width);
    vars->img_minimap_f = mlx_xpm_file_to_image(vars->mlx, "sprites/floor.xpm", &vars->height , &vars->width);
    ft_minimap(vars);   
    
    vars->line = mlx_new_image(vars->mlx, 800, 600); // Crée l’image pour la ligne
    img.img = vars->line;
    img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);

    draw_line_angle(&img, vars->x, vars->y, 500, 45, 0xfa0505);

    // Afficher l’image
    mlx_put_image_to_window(vars->mlx, vars->win, vars->line, vars->x, vars->y);
    
    mlx_hook(vars->win, 2, (1L << 0), keyhook, vars);
	mlx_hook(vars->win, 17, 0, ft_exit, vars);
    mlx_loop(vars->mlx);
    return (0);
}

void copy(t_vars *vars)
{
    char *line;
    int i;
    int fd;

    fd = open(vars->filename, O_RDONLY);
    if (fd == -1)
        ft_close_exit(vars, "Error\nFile error\n");

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

int copy_map(t_vars *vars)
{
    vars->len_y = ft_lastline(vars->filename);

    if (!check_borders(vars->map, vars->len_y))
    {
        ft_close_exit(vars, "Error\nMap non fermée par des murs !");
        return (1);
    }

    print_tab(vars->map);
    return (0);
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

int clean(t_vars *vars)
{
    free_tabtab(vars->map);
    free(vars->NO);
    free(vars->EA);
    free(vars->SO);
    free(vars->WE);
    return (0);
}

int check_borders(char **map, int len_y)
{
    int i = 0;
    int j;
    int len_x;

    if (!map || len_y == 0)
        return (0);

    len_x = ft_strlen(map[0]);

    j = 0;
    while (j < len_x)
    {
        if (map[0][j] != '1' || map[len_y - 1][j] != '1')
            return (0);
        j++;
    }

    while (i < len_y)
    {
        len_x = ft_strlen(map[i]);
        if (map[i][0] != '1' || map[i][len_x - 1] != '1')
            return (0);
        i++;
    }

    return (1);
}


int main(int argc, char *argv[])
{
    t_vars vars;
    vars_init(&vars, argv[1]);
    (void)argc;
    // Parsing
    printf("FILENAME : %s\n", vars.filename);
    copy_map(&vars);
    
    launch(&vars);
}