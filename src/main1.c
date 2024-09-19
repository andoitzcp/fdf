#include "fdf.h"
#include <stdio.h>

void ft_print_square(void *mlx, void* win, int color)
{
    int  i;
    int  j;

    i = 40;
    j = 40;
    while (i <= 360)
    {
        while (j <= 360)
        {
            mlx_pixel_put(mlx, win, j, i, color);
            j++;
        }
        i++;
        j = 40;
    }

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
    xoffset = 900;
    yoffset = 500;
    v = 0;
    printf("flag01: %d\n", yoffset);
    while (v < 500)
    {
        x = (int)(-v * cos(M_PI_4 / 3)) + xoffset;
        y = (int)(v * sin(M_PI_4 / 3)) + yoffset;

        printf("v: %d, x: %d, y: %d\n", v, x, y);
        mlx_pixel_put(mlx, win, x, y, color);
        v++;
    }
    xoffset = 900 - (int)(500 * cos(M_PI_4 / 3));
    yoffset = 500 + (int)(500 * sin(M_PI_4 / 3));
    v = 0;
    printf("flag02: %d\n", yoffset);
    while (v < 500)
    {
        x = (int)(v * cos(M_PI_4 / 3)) + xoffset;
        y = (int)(v * sin(M_PI_4 / 3)) + yoffset;

        printf("v: %d, x: %d, y: %d\n", v, x, y);
        mlx_pixel_put(mlx, win, x, y, color);
        v++;
    }
    xoffset = 900 + (int)(500 * cos(M_PI_4 / 3));
    yoffset = 500 + (int)(500 * sin(M_PI_4 / 3));
    v = 0;
    printf("flag03: %d\n", yoffset);
    while (v < 500)
    {
        x = (int)(-v * cos(M_PI_4 / 3)) + xoffset;
        y = (int)(v * sin(M_PI_4 / 3)) + yoffset;

        printf("v: %d, x: %d, y: %d\n", v, x, y);
        mlx_pixel_put(mlx, win, x, y, color);
        v++;
    }

}

int main(void)
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 1920, 1080, "Testing");
    //ft_print_square(mlx, win, 0x00FF0000);
    //ft_print_square(mlx, win, 0x000000FF);
    //ft_print_square(mlx, win, 0x000000FF);
    ft_print_axis(mlx, win, 0x000000FF);
    mlx_loop(mlx);

    return (0);
}
