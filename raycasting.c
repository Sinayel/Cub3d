/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judenis <judenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:35:12 by judenis           #+#    #+#             */
/*   Updated: 2025/03/10 16:56:53 by judenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void draw_line_angle(t_img *img, int x0, int y0, int length, double angle_deg, int color)
{
    double angle_rad = angle_deg * (M_PI / 180.0); // Conversion en radians
    int x1 = x0 + length * cos(angle_rad);
    int y1 = y0 + length * sin(angle_rad);

    draw_line(img, x0, y0, x1, y1, color);
}

void put_pixel(t_img *img, int x, int y, int color)
{
    char    *dst;

    if (x < 0 || y < 0 || x >= img->line_length / (img->bpp / 8) || y >= 600) // Vérifie les limites de l'image
        return;
    dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
    *(unsigned int *)dst = color;
}

void draw_line(t_img *img, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;
    int e2;

    while (1)
    {
        put_pixel(img, x0, y0, color);
        if (x0 == x1 && y0 == y1)
            break;
        e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x0 += sx; }
        if (e2 < dx) { err += dx; y0 += sy; }
    }
}