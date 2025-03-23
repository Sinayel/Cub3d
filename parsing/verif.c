#include "../includes/cub3d.h"

void jsp(t_vars *vars)
{
    int i = 0;
    int j = 0;
    while(vars->map[i] != NULL)
    {
        if(vars->map[i][j] == ' ')
        printf("%s", vars->map[i]);
        i++;
    }
}
