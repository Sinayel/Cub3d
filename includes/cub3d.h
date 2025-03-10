/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judenis <judenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:22:17 by ylouvel           #+#    #+#             */
/*   Updated: 2025/03/10 12:03:22 by judenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# define BUFFER_SIZE 42

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include <../libft/libft.h>
#include "../minilibx/mlx.h"

typedef struct s_vars
{
    void *mlx;
    void *win;

    char **map;
    int len_x;
    int len_y;

    // textures
    char *NO;
    char *SO;
    char *WE;
    char *EA;
    int floor[3]; //! Verifier si 0 <= R/G/B <= 255
    int ceiling[3]; //! Verifier si 0 <= R/G/B <= 255

    int facing; //! 0 <= x <= 359
    int x;
    int y;
    
}               t_vars;

char	*get_next_line(int fd);

int keyhook(int keycode, t_vars *vars);
int ft_exit(t_vars *vars);


int	ft_lenline(char *filename);
int	ft_lastline(char *filename);

int	begining_of_map(char *filename);

#endif
