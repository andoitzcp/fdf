/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_printing.c                                :+:    :+: :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: andoitzcp <andoitzcp@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 01:20:30 by andoitzcp         #+#    #+#             */
/*   Updated: 2025/02/14 01:44:24 by andoitzcp   ########  ###                */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_not_printed(t_node **head)
{
	t_node	*p;
	t_node	*tmp;

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

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_print_vector(t_var *var, t_node *a, t_node *b)
{
	t_calcs	c;

	c.mod = (int)hypot(a->carx - b->carx, a->cary - b->cary);
	c.c = (double)(b->carx - a->carx) / c.mod;
	c.s = (double)(b->cary - a->cary) / c.mod;
	c.i = 0;
	while (c.i < c.mod)
	{
		c.x = (int)(c.i * c.c + a->carx);
		c.y = (int)(c.i * c.s + a->cary);
		c.z = a->c + c.i * (b->c - a->c) / c.mod;
		if (var->canvas_mode == 0)
			mlx_pixel_put(var->mlx, var->win, c.x, c.y, c.z);
		if (var->canvas_mode == 1 && c.x < SCRN_WIDTH && c.y < SCRN_HEIGH)
			my_mlx_pixel_put(&var->img, c.x, c.y, c.z);
		c.i++;
	}
}

void	ft_link_point(t_node *p, t_var *var)
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

void	printgrid(t_node **head, t_var *var)
{
	t_node	*p;
	t_node	*tmp;

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
		mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
	ft_set_not_printed(head);
}
