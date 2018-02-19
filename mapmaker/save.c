/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:18:23 by aderby            #+#    #+#             */
/*   Updated: 2017/09/21 19:13:51 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_maker.h"

int			**fill_map(void)
{
	int	**map;
	int	i;

	i = -1;
	map = (int **)ft_memalloc(sizeof(int *) * H);
	while (++i < H)
		map[i] = (int *)ft_memalloc(sizeof(int) * W);
	i = -1;
	while (++i < H)
		map[i][0] = 1;
	while (i-- > 0)
		map[H - 1][i - 1] = 1;
	while (++i < H)
		map[i][H - 1] = 1;
	while (--i >= 0)
		map[0][i] = 1;
	return (map);
}

void	save_map(t_e *e)
{
	int i;
	int j;
	int x;
	int y;
	int fd;

	i = 0;
	j = 1;
	y = 1;
	e->map = fill_map();
	fd = open("map.wolf3d", O_CREAT | O_RDWR);
	while (y < H - 1)
	{
		x = 1;
		i = 1;
		while (x < W - 1)
		{
			if (e->img->data[x + y * e->img->size] == 0xFFFFFF)
				e->map[j][i] = 1;
			if (e->img->data[x + y * e->img->size] == 0xFF0000)
				e->map[j][i] = 2;
			x += 10;
			i++;
		}
		y += 10;
		j++;
	}
	ft_putstr("map saved\n");
	j = 0;
	while (j < H)
	{
		i = 0;
		while (i < H)
		{
			ft_putnbr_fd(e->map[j][i], fd);
			i++;
		}
		ft_putchar_fd('\n', fd);
		j++;
	}
}
