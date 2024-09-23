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
    p->c = MIN_COLOR + p->z * (MAX_COLOR - MIN_COLOR) / 255;
    //p->c = ft_atoi(handc[1]); falta crear funcion xtoi
    p->is_printed = 0;
    p->u = NULL;
    p->d = NULL;
    p->r = NULL;
    return (p);
}

t_node *ft_relocpoint(t_node *p, t_params *par)
{
    double isox;
    double isoy;

    isox = (double)p->x;
    isoy = (double)p->y;

    p->x = ((isox - isoy) / 1.5) * par->module;
    p->y = (isox / 3 + isoy / 1.5) * par->module;
    p->x += SCRN_WIDTH / 2;
    p->y += SCRN_HEIGH / 2 - p->z;
    return (p);
}

t_node **ft_resetgrid(t_node **head, t_params *par)
{
    int i;
    int j;
    t_node *p;
    t_node *tmp;

    p = *head;
    i = 0;
    while (p)
    {
        p = p->r;
        i++;
    }
    p = *head;
    j = 0;
    while (p)
    {
        p = p->d;
        j++;
    }
    if (j > i)
        par->module = SCRN_HEIGH / j / 2;
    else
        par->module = SCRN_WIDTH / i / 2;
    par->angle = (double)M_PI_4 / 3;
    p = *head;
    while (p)
    {
        tmp = p;
        while (tmp)
        {
            tmp = ft_relocpoint(tmp, par);
            tmp = tmp->r;
        }
        p = p->d;
    }
    return (head);
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

int main(int argc, char **argv)
{
    void *mlx;
    void *win;
    t_node **head;
    t_params *par;
    //int node_dist;

    if (argc != 2)
        return (1);
    mlx = mlx_init();
    win = mlx_new_window(mlx, SCRN_WIDTH, SCRN_HEIGH, "Testing");
    ft_print_limits(mlx, win, 0x00FF0000);
    head = ft_parsefile(argv[1]);
    par = (t_params *)malloc(sizeof(t_params));
    head = ft_resetgrid(head, par);
    //db_printmatrix(head);
    printgrid(head, mlx, win);
    //ft_link_point(a, mlx, win);
    mlx_loop(mlx);

    return (0);
}
