/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 13:21:43 by aderby            #+#    #+#             */
/*   Updated: 2017/09/21 15:03:40 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_maker.h"

void	draw_tile(t_e *e)
{
	int x;
	int y;
	int xl;
	int yl;

	x = e->button.mouse_pos.x / 10;
	y = e->button.mouse_pos.y / 10;
	x *= 10;
	y *= 10;
	xl = x + 10;
	yl = y + 10;
	while (y++ < yl - 1)
	{
		x = xl - 9;
		while (x < xl)
		{
			e->img->data[x + y * e->img->size] = e->color;
			x++;
		}
	}
}

int		loop_hook(t_e *e)
{
	if (e->button.mouse)
	{
		draw_tile(e);
		e->draw = 1;
	}
	if (e->draw == 1)
	{
		e->draw = 0;
		mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0);
	}
	return (0);
}

int		mousep_hook(int key, int x, int y, t_e *e)
{
//	ft_putnbr(x);
//	ft_putnbr(y);
	if (key == 1)
		e->button.mouse = 1;
	return (key);
}

int		mouser_hook(int key, int x, int y, t_e *e)
{
//	ft_putnbr(x);
//	ft_putnbr(y);
	if (key == 1)
		e->button.mouse = 0;
	return (key);
}

int		mousem_hook(int x, int y, t_e *e)
{
//	ft_putnbr(x);
//	ft_putnbr(y);
	e->button.mouse_pos.x = x;
	e->button.mouse_pos.y = y;
	return (x);
}
