/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylouvel <ylouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:38:52 by judenis           #+#    #+#             */
/*   Updated: 2025/03/10 18:26:39 by ylouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int ft_exit(t_vars *vars)
{
    free_tabtab(vars->map);
    mlx_destroy_image(vars->mlx, vars->img_minimap_f);
    mlx_destroy_image(vars->mlx, vars->img_minimap_w);
    mlx_destroy_image(vars->mlx, vars->img_minimap_p);
    mlx_destroy_image(vars->mlx, vars->line);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

void move_cam(int keycode, t_vars *vars)
{
    if (keycode == 65361) // gauche //? Peut etre mettre l'intensite de decalage de cam dans la struct ????
    {
        vars->facing -= 1;
        if (vars->facing < 0)
            vars->facing = 359;
    }
    if (keycode == 65363) // droite
    {
        vars->facing += 1;
        if (vars->facing > 359)
            vars->facing = 0;
    }
    printf("%d\n", vars->facing);
}

int keyhook(int keycode, t_vars *vars)
{
    if (keycode == 65361 || keycode == 65363)
        move_cam(keycode, vars);
    if (keycode == 119) // W //? Peut etre mettre la vitesse de dpcm dans la struct ????
        vars->y -= 10;
    if (keycode == 97) // A
        vars->x -= 10;
    if (keycode == 115) // S
        vars->y += 10;
    if (keycode == 100) // D
        vars->x += 10;
    if (keycode == 65307) // Echap
        ft_exit(vars);
    print_tab(vars->map);
    printf("keycode : %d\nx : %d, y : %d\n", keycode, vars->x, vars->y);
    ft_minimap(vars);
    return (0);
}
