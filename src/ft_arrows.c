/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrows.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 20:53:03 by kshcherb          #+#    #+#             */
/*   Updated: 2017/02/19 17:31:28 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_key_barrow(t_var *var)
{
	int		res;

	var->sdvigy += 25;
	res = mlx_clear_window(var->mlx, var->win);
	ft_transform(var);
	ft_drawlines(var);
}

void		ft_key_tarrow(t_var *var)
{
	int		res;

	var->sdvigy -= 25;
	res = mlx_clear_window(var->mlx, var->win);
	ft_transform(var);
	ft_drawlines(var);
}

void		ft_key_larrow(t_var *var)
{
	int		res;

	var->sdvigx -= 25;
	res = mlx_clear_window(var->mlx, var->win);
	ft_transform(var);
	ft_drawlines(var);
}

void		ft_key_rarrow(t_var *var)
{
	int		res;

	var->sdvigx += 25;
	res = mlx_clear_window(var->mlx, var->win);
	ft_transform(var);
	ft_drawlines(var);
}

void		ft_arrows(int kcode, t_var *var)
{
	if (kcode == 123)
		ft_key_larrow(var);
	if (kcode == 124)
		ft_key_rarrow(var);
	if (kcode == 125)
		ft_key_barrow(var);
	if (kcode == 126)
		ft_key_tarrow(var);
	ft_info(var);
}
