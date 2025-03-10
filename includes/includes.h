/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judenis <judenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:22:17 by ylouvel           #+#    #+#             */
/*   Updated: 2025/03/10 10:07:28 by judenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../minilibx/mlx.h"

typedef struct s_vars
{
    void *mlx;
    void *win;

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

#endif
