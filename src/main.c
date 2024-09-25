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

void ft_freegrid(t_node **head)
{
    t_node *p;
    t_node *tmp;

    p = *head;
    while (p)
    {
        tmp = p;
        p = p->d;
        while (tmp->r)
        {
            tmp = tmp->r;
            free(tmp->l);
        }
        free(tmp);
    }
    free(head);
}

void ft_resize(t_var *var, int xmov, int ymov, int rsize)
{
    var->par->xoffset = var->par->xoffset + xmov;
    var->par->yoffset = var->par->yoffset + ymov;
    var->par->width = var->par->width + rsize;
    ft_recalcgrid(var->head, var->par);
    mlx_clear_window(var->mlx, var->win);
    printf("here1\n");
    if (var->canvas_mode == 1 && var->img.img)
    {
        printf("here2\n");
        mlx_destroy_image(var->mlx, var->img.img);
        printf("here3\n");
        var->img.img = mlx_new_image(var->mlx, SCRN_WIDTH, SCRN_HEIGH);
        printf("here4\n");
    }
    printf("here5\n");
    printgrid(var->head, var);
    printf("here6\n");
}

int ft_close(t_var *var)
{
    mlx_destroy_window(var->mlx, var->win);
    ft_freegrid(var->head);
    mlx_loop_end(var->mlx);
    mlx_destroy_display(var->mlx);
    free(var->par);
    free(var->mlx);
    exit(0);
}

int ft_keyhook(int keycode, t_var *var)
{
    printf("%d\n", keycode);
    if (keycode == 99)
    {
        if (var->canvas_mode == 0)
            var->canvas_mode = 1;
        else
            var->canvas_mode = 0;
    }
    else if (keycode == 104)
        ft_resize(var, -50, 0, 0);
    else if (keycode == 106)
        ft_resize(var, 0, 50, 0);
    else if (keycode == 107)
        ft_resize(var, 0, -50, 0);
    else if (keycode == 108)
        ft_resize(var, +50, 0, 0);
    else if (keycode == 117)
        ft_resize(var, 0, 0, 50);
    else if (keycode == 109)
        ft_resize(var, 0, 0, -50);
    else if (keycode == 65307)
    {
        ft_close(var);
    }
    return (0);
}


int main(int argc, char **argv)
{
    t_var var;

    if (argc != 2)
        return (1);
    var.mlx = mlx_init();
    var.win = mlx_new_window(var.mlx, SCRN_WIDTH, SCRN_HEIGH, "FdF");
    var.img.img = mlx_new_image(var.mlx, SCRN_WIDTH, SCRN_HEIGH);
    var.img.addr = mlx_get_data_addr(var.img.img, &var.img.bits_per_pixel, &var.img.line_length, &var.img.endian);
    ft_print_limits(var.mlx, var.win, 0x00FF0000);
    var.canvas_mode = 0;
    var.head = ft_parsefile(argv[1]);
    //db_printmatrix(var.head);
    var.par = ft_setinitparams(var.head);
    var.head = ft_recalcgrid(var.head, var.par);
    db_printmatrix(var.head);
    printgrid(var.head, &var);
    mlx_hook(var.win, 17, 0, ft_close, &var);
    mlx_hook(var.win, 2, 1L<<0, ft_keyhook, &var);
    mlx_loop(var.mlx);

    return (0);
}
