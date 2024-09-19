#include "fdf.h"
#include <stdio.h>

void ft_print_square(void *mlx, void* win, int color)
{
    int  i;
    int  j;

    i = 60;
    j = 60;
    while (i <= 1860)
    {
        while (j <= 1860)
        {
            mlx_pixel_put(mlx, win, j, i, color);
            j++;
        }
        i++;
        j = 40;
    }

}

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

void ft_print_axis(void *mlx, void *win, int color)
{
    int v;
    int x;
    int y;
    int xoffset;
    int yoffset;


    xoffset = 900;
    yoffset = 500;
    v = 0;
    printf("flag00: %d\n", yoffset);
    while (v < 500)
    {
        x = (int)(v * cos(M_PI_4 / 3)) + xoffset;
        y = (int)(v * sin(M_PI_4 / 3)) + yoffset;

        printf("v: %d, x: %d, y: %d\n", v, x, y);
        mlx_pixel_put(mlx, win, x, y, color);
        v++;
    }
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
    printf("flag00:mod %d\n", mod);
    printf("flag01:ax %d\tay %d\n", a->x, a->y);
    printf("flag02:fx %d\tby %d\n", b->x, b->y);
    c = (double)(b->x - a->x) / mod;
    s = (double)(b->y - a->y) / mod;
    printf("flag03:fc %f\ts %f\n", c, s);
    i = 0;
    while (i < mod)
    {
        x = (int)(i * c + a->x);
        y = (int)(i * s + a->y);
        printf("v: %d, x: %d, y: %d\n", mod, x, y);
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

t_node *ft_defpoint(int x, int y)
{
    t_node *p;

    p = (t_node *)malloc(sizeof(t_node));
    p->x = x;
    p->y = y;
    p->z = 0;
    p->is_printed = 0;
    return (p);
}

int main(void)
{
    void *mlx;
    void *win;
    t_node *a;
    t_node *b;
    t_node *c;
    t_node *d;
    t_node *e;
    //:int node_dist;

    mlx = mlx_init();
    win = mlx_new_window(mlx, SCRN_WIDTH, SCRN_HEIGH, "Testing");
    //ft_print_square(mlx, win, 0x00FF0000);
    ft_print_limits(mlx, win, 0x00FF0000);
    //node_dist = SCRN_WIDTH / 50;
    //ft_print_square(mlx, win, 0x000000FF);
    //ft_print_square(mlx, win, 0x000000FF);
    //ft_print_axis(mlx, win, 0x000000FF);
    a = ft_defpoint(700, 500);
    b = ft_defpoint(100, 500);
    c = ft_defpoint(1500, 600);
    d = ft_defpoint(500, 100);
    e = ft_defpoint(400, 900);
    a->l = b;
    a->r = c;
    a->u = d;
    a->d = e;
    ft_link_point(a, mlx, win);
    mlx_loop(mlx);

    return (0);
}
