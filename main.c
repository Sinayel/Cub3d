/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judenis <judenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:31:08 by judenis           #+#    #+#             */
/*   Updated: 2025/03/10 10:31:57 by judenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/includes.h"

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
}

int keyhook(int keycode, t_vars *vars)
{
    if (keycode == 65361 || keycode == 65363)
        move_cam(keycode, vars);
    printf("%d\n", vars->facing);
    return (0);
}

int launch(t_vars *vars)
{
    vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1920, 1080,
			"cub3D");
    mlx_hook(vars->win, 2, (1L << 0), keyhook, vars);
    mlx_loop(vars->mlx);
    return (0);
}


void vars_init(t_vars *vars)
{
    // E = 0 / N = pi/2 / O = pi / S 3pi/2
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
    (void)argv;
    // Parsing
    
    launch(&vars);
    
}