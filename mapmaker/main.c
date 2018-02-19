/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 12:41:14 by aderby            #+#    #+#             */
/*   Updated: 2017/09/21 15:05:20 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_maker.h"

void	draw_grid(t_e *e)
{
	int x;
	int y;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			if (x % 10 == 0 || y % 10 == 0)
				e->img->data[x + (y * e->img->size)] = 0x959595;
			x++;
		}
		y++;
	}
	e->draw = 1;
}

int		main(void)
{
	void	*mlx;
	t_e		*e;

	mlx = mlx_init();
	e = initialize_environment(mlx, W, H, "Map Maker");
	draw_grid(e);
	mlx_loop_hook(mlx, loop_hook, e);
	mlx_loop(mlx);
}
