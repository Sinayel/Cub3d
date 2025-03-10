#include <math.h>
#include "minilibx/mlx.h"
#include <stdlib.h>
#include <stdio.h>

#define WIDTH  500
#define HEIGHT 500

typedef struct s_img {
    void    *img;
    char    *addr;
    int     bpp;
    int     line_length;
    int     endian;
} t_img;

typedef struct s_vars {
    void    *mlx;
    void    *win;
    t_img   img;
} t_vars;

void my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    char *dst;

    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
    {
        dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
        *(unsigned int*)dst = color;
    }
}

void rotate_image(t_img *src, t_img *dst, double angle)
{
    int x, y, new_x, new_y;
    double rad = angle * M_PI / 180.0;
    int cx = WIDTH / 2, cy = HEIGHT / 2;

    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            new_x = cos(rad) * (x - cx) - sin(rad) * (y - cy) + cx;
            new_y = sin(rad) * (x - cx) + cos(rad) * (y - cy) + cy;

            if (new_x >= 0 && new_x < WIDTH && new_y >= 0 && new_y < HEIGHT)
            {
                int pixel = *(int*)(src->addr + (y * src->line_length + x * (src->bpp / 8)));
                my_mlx_pixel_put(dst, new_x, new_y, pixel);
            }
        }
    }
}

int main()
{
    t_vars vars;
    t_img rotated_img;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Rotation");

    vars.img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
    vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bpp, &vars.img.line_length, &vars.img.endian);

    rotated_img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
    rotated_img.addr = mlx_get_data_addr(rotated_img.img, &rotated_img.bpp, &rotated_img.line_length, &rotated_img.endian);

    // Dessin d'un carré simple (exemple)
    for (int y = 200; y < 300; y++)
        for (int x = 200; x < 300; x++)
            my_mlx_pixel_put(&vars.img, x, y, 0x00FF0000); // Rouge

    // Appliquer la rotation
    rotate_image(&vars.img, &rotated_img, 30.0);

    // Afficher l'image tournée
    mlx_put_image_to_window(vars.mlx, vars.win, rotated_img.img, 0, 0);

    mlx_loop(vars.mlx);
    return (0);
}