/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 21:18:42 by kshcherb          #+#    #+#             */
/*   Updated: 2017/02/08 21:03:09 by kshcherb         ###   ########.fr       */
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
#include <stdio.h>

int			ft_readfile(char *s);

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
	int					i;
	int					x;
	int					y;
	int					max;
	int					fd;
}						t_var;

#endif
