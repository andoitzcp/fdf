#include "fdf.h"

void ft_set_not_printed(t_node **head)
{
    t_node *p;
    t_node *tmp;

    p = *head;
    while (p)
    {
        tmp = p;
        while (tmp)
        {
            tmp->is_printed = 0;
            tmp = tmp->r;
        }
        p = p->d;
    }
}

void my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void ft_print_vector(t_var *var, t_node *a, t_node *b)
{
    int mod;
    double i;
    double s;
    double c;
    unsigned int x;
    unsigned int y;
    int z;

    mod = (int)hypot(a->carx - b->carx, a->cary - b->cary);
    c = (double)(b->carx - a->carx) / mod;
    s = (double)(b->cary - a->cary) / mod;
    i = 0;
    while (i < mod)
    {
        x = (int)(i * c + a->carx);
        y = (int)(i * s + a->cary);
        z = a->c + i * (b->c - a->c) / mod;
        if (var->canvas_mode == 0)
            mlx_pixel_put(var->mlx, var->win, x, y, z);
        if (var->canvas_mode == 1 && x < SCRN_WIDTH && y < SCRN_HEIGH)
            my_mlx_pixel_put(&var->img, x, y, z);
        i++;
    }
}

void ft_link_point(t_node *p, t_var *var)
{
    if (p->u && p->u->is_printed == 0)
        ft_print_vector(var, p, p->u);
    if (p->d && p->d->is_printed == 0)
        ft_print_vector(var, p, p->d);
    if (p->l && p->l->is_printed == 0)
        ft_print_vector(var, p, p->l);
    if (p->r && p->r->is_printed == 0)
        ft_print_vector(var, p, p->r);
    p->is_printed = 1;
}

void printgrid(t_node **head, t_var *var)
{
    t_node *p;
    t_node *tmp;

    p = *head;
    while (p)
    {
        tmp = p;
        while (tmp)
        {
            ft_link_point(tmp, var);
            tmp = tmp->r;
        }
        p = p->d;
    }
    if (var->canvas_mode == 1)
    {
        mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
        printf("flag:img\n");
    }
    printf("flag:pixel\n");
    ft_set_not_printed(head);
}
