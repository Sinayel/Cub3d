/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judenis <judenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:55:40 by judenis           #+#    #+#             */
/*   Updated: 2025/03/10 16:19:02 by judenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void ft_minimap(t_vars *vars)
{
    int i;
    int j;

    i = 0;
    while (vars->map[i])
    {
        j = 0;
        while (vars->map[i][j])
        {
            if (vars->map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img_minimap_w, j
					* 10, i * 10);
			if (vars->map[i][j] == '0' || vars->map[i][j] == 'N')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img_minimap_f,
					j * 10, i * 10);
            j++;
        }
        i++;
    }
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_minimap_p, vars->x,
		vars->y);
}
