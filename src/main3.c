#include "fdf.h"
#include <stdio.h>


void ft_print_limits(void *mlx, void* win, int color)
{
    int  i;
    i = 60;
    while (i++ <= 1860)
        mlx_pixel_put(mlx, win, 60, i, color);
    i = 60;
    while (i++ <= 1860)
        mlx_pixel_put(mlx, win, 1860, i, color);
    i = 60;
    while (i++ <= 1860)
        mlx_pixel_put(mlx, win, i, 60, color);
    i = 60;
    while (i++ <= 1860)
        mlx_pixel_put(mlx, win, i, 1860, color);
}


void ft_print_vector(void *mlx, void *win, t_node *a, t_node *b)
{
    int mod;
    double i;
    double s;
    double c;
    int x;
    int y;

    mod = (int)hypot(a->x - b->x, a->y - b->y);
    c = (double)(b->x - a->x) / mod;
    s = (double)(b->y - a->y) / mod;
    i = 0;
    while (i < mod)
    {
        x = (int)(i * c + a->x);
        y = (int)(i * s + a->y);
        mlx_pixel_put(mlx, win, x, y, 0x00FF0000);
        i++;
    }
}

void ft_link_point(t_node *p, void *mlx, void *win)
{
    ft_print_vector(mlx, win, p, p->u);
    ft_print_vector(mlx, win, p, p->d);
    ft_print_vector(mlx, win, p, p->l);
    ft_print_vector(mlx, win, p, p->r);
}

t_node *ft_defpoint(int x, int y, char *param)
{
    t_node *p;
    char **handc;

    p = (t_node *)malloc(sizeof(t_node));
    if (!p)
    {
        perror("Could not allocate node pointer\n");
        abort();
    }
    handc = ft_split(param, ',');
    p->x = x;
    p->y = y;
    p->z = ft_atoi(handc[0]);
    //p->c = ft_atoi(handc[1]); falta crear funcion xtoi
    p->is_printed = 0;
    p->u = NULL;
    p->d = NULL;
    p->r = NULL;
    return (p);
}

int main(void)
{
    void *mlx;
    void *win;
    //int node_dist;
    t_node **matrix;
    int i;
    int j;
    int k;

    mlx = mlx_init();
    win = mlx_new_window(mlx, SCRN_WIDTH, SCRN_HEIGH, "Testing");
    ft_print_limits(mlx, win, 0x00FF0000);
    //node_dist = SCRN_WIDTH / 50;
    matrix = (t_node **)malloc(50 * 50 * sizeof(t_node *));
    k = 0;
    i = 0;
    while (i < 50)
    {
        j = 0;
        while (j < 50)
        {
            matrix[k] = ft_defpoint(j, i, 0);
            k++;
            j++;
        }
        i++;
    }
    k = 0;
    //ft_link_point(a, mlx, win);
    mlx_loop(mlx);

    return (0);
}
