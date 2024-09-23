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

int main(int argc, char **argv)
{
    void *mlx;
    void *win;
    //int node_dist;

    if (argc != 2)
        return (1);
    mlx = mlx_init();
    win = mlx_new_window(mlx, SCRN_WIDTH, SCRN_HEIGH, "Testing");
    ft_print_limits(mlx, win, 0x00FF0000);
    ft_parsefile(argv[1]);
    //ft_link_point(a, mlx, win);
    //mlx_loop(mlx);

    return (0);
}
