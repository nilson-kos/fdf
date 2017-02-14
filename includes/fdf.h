/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 21:18:42 by kshcherb          #+#    #+#             */
/*   Updated: 2017/02/13 17:58:38 by kshcherb         ###   ########.fr       */
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
	t_coord				*coord;
}						t_var;

t_var					*ft_readfile(char *s);
void					ft_drawlines(t_var *var);

#endif
