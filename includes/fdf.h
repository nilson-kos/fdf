/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 21:18:42 by kshcherb          #+#    #+#             */
/*   Updated: 2017/02/17 21:34:12 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H
# define __FDF_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx.h"
# include <math.h>
# define A (var->alfa * M_PI / 180)
# define B (var->beta * M_PI / 180)
# define G (var->gama * M_PI / 180)

typedef struct 			s_coord
{
	int					x;
	int					y;
	int					z;
	int					rgb;
	struct	s_coord		*next;
}						t_coord;

typedef struct			s_var
{
	void				*mlx;
	void				*win;
	int					shiftX;
	int					shiftY;
	int					i;
	int					x;
	int					y;
	int					rgb;
	int					max;
	int					may;
	int					fd;
	int					deltaX;
	int					deltaY;
	int					signX;
	int					signY;
	int					error;
	int					error2;
	int					x1;
	int					x2;
	int					y1;
	int					y2;
	int					yy;
	int					xx;
	int					alfa;
	int					beta;
	int					gama;
	int					zoomM;
	int					zoomP;
	int					upz;
	t_coord				*coord;
}						t_var;

t_var					*ft_readfile(char *s);
t_var					*ft_transform(t_var *var);
void					ft_drawlines(t_var *var);
int						ft_ch_big(char **mass);
void					ft_ch_smal(char **mass, int max);
int						ft_key_events(int keycode, t_var *var);
void					ft_arrows(int kcode, t_var *var);
void					ft_zoom(int kcode, t_var *var);

#endif
