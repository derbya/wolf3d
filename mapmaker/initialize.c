/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 12:43:59 by aderby            #+#    #+#             */
/*   Updated: 2017/09/21 14:56:00 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_maker.h"

void	initialize_hooks(t_e *e)
{
	mlx_hook(e->win, 2, 0, key_hook, e);
	mlx_hook(e->win, 3, 0, keyr_hook, e);
	mlx_hook(e->win, 4, 0, mousep_hook, e);
	mlx_hook(e->win, 5, 0, mouser_hook, e);
	mlx_hook(e->win, 6, 0, mousem_hook, e);
	mlx_hook(e->win, 12, 0, expose_hook, e);
	mlx_hook(e->win, 17, 0, exit_hook, e);
}

t_img	*init_image(void *mlx, int w, int h)
{
	t_img	*i;

	i = (t_img *)ft_memalloc(sizeof(t_img));
	i->img = mlx_new_image(mlx, w, h);
	i->data = (int *)mlx_get_data_addr(i->img, &i->bbp, &i->size, &i->e);
	return (i);
}

t_e		*initialize_environment(void *mlx, int w, int h, char *title)
{
	t_e		*new;
	t_img	*img;

	new = (t_e *)ft_memalloc(sizeof(t_e));
	new->mlx = mlx;
	new->win = mlx_new_window(mlx, w, h, title);
	new->map = NULL;
	new->color = 0xFFFFFF;
	img = init_image(mlx, w, h);
	img->size /= 4;
	new->img = img;
	initialize_hooks(new);
	return (new);
}
