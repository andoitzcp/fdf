#include "fdf.h"

void ft_print_vector(void *mlx, void *win, t_node *a, t_node *b)
{
    int mod;
    double i;
    double s;
    double c;
    int x;
    int y;
    int z;

    mod = (int)hypot(a->x - b->x, a->y - b->y);
    c = (double)(b->x - a->x) / mod;
    s = (double)(b->y - a->y) / mod;
    i = 0;
    while (i < mod)
    {
        x = (int)(i * c + a->x);
        y = (int)(i * s + a->y);
        z = b->c + i * (b->c - a->c) / mod;
        mlx_pixel_put(mlx, win, x, y, z);
        i++;
    }
}

void ft_link_point(t_node *p, void *mlx, void *win)
{
    if (p->u && p->is_printed == 0)
        ft_print_vector(mlx, win, p, p->u);
    if (p->d && p->is_printed == 0)
        ft_print_vector(mlx, win, p, p->d);
    if (p->l && p->is_printed == 0)
        ft_print_vector(mlx, win, p, p->l);
    if (p->r && p->is_printed == 0)
        ft_print_vector(mlx, win, p, p->r);
    p->is_printed = 1;
}

void printgrid(t_node **head, void *mlx, void *win)
{
    t_node *p;
    t_node *tmp;

    p = *head;
    while (p)
    {
        tmp = p;
        while (tmp)
        {
            ft_link_point(tmp, mlx, win);
            db_printpoint(tmp);
            tmp = tmp->r;
        }
        p = p->d;
    }
}
