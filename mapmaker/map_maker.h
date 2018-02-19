/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 16:58:50 by aderby            #+#    #+#             */
/*   Updated: 2017/09/21 15:19:12 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_MAKER_H
# define MAP_MAKER_H

# include "libft/inc/libft.h"
# include "miniLibx/mlx.h"
# include <fcntl.h>
# include <math.h>

/*
** ┌────────────────────────────────────────────────┐
** │ USEFUL        MACROS         ARE        USEFUL │
** └────────────────────────────────────────────────┘
*/

# define H 1000
# define W 1000

/*
** ┌────────────────────────────────────────────────┐
** │ NORM               SUCKS             EGGPLANTS │
** └────────────────────────────────────────────────┘
*/


/*
** ┌────────────────────────────────────────────────┐
** │                   STRUCTS                      │
** └────────────────────────────────────────────────┘
*/

typedef struct		s_img
{
	int				*data;
	int				bbp;
	int				size;
	int				e;
	void			*img;
}					t_img;

typedef struct		s_coord
{
	double			x;
	double			y;
}					t_coord;

typedef struct		s_button
{
	int				w;
	int				a;
	int				s;
	int				d;
	int				q;
	int				e;
	int				mouse;
	t_coord			mouse_pos;
}					t_button;

typedef struct		s_e
{
	int				color;
	int				draw;
	int				**map;
	void			*mlx;
	void			*win;
	t_img			*img;
	t_coord			s_pos;
	t_coord			plane;
	t_coord			direction;
	t_button		button;
}					t_e;

/*
** ┌────────────────────────────────────────────────┐
** │                  PROTOTYPES                    │
** └────────────────────────────────────────────────┘
*/

t_e					*initialize_environment(void *m, int w, int h, char *t);
int					key_hook(int keycode, t_e *e);
int					keyr_hook(int keycode, t_e *e);
int					expose_hook(t_e *e);
int					exit_hook(t_e *e);
int					mousep_hook(int key,int x, int y, t_e *e);
int					mouser_hook(int key,int x, int y, t_e *e);
int					mousem_hook(int x, int y, t_e *e);
int					loop_hook(t_e *e);
void				save_map(t_e *e);

#endif
