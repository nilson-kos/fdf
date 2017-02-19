/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_angle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 14:37:19 by kshcherb          #+#    #+#             */
/*   Updated: 2017/02/19 18:34:21 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_alfa(int kcode, t_var *var)
{
	int	res;

	if (kcode == 91)
	{
		var->alfa += 5;
		var->infoalpha += 5;
	}
	if (kcode == 84)
	{
		var->infoalpha -= 5;
		var->alfa -= 5;
	}
	if (var->infoalpha > 360)
		var->infoalpha = 5;
	if (var->infoalpha < 0)
		var->infoalpha = 355;
	res = mlx_clear_window(var->mlx, var->win);
	ft_transform(var);
	ft_drawlines(var);
}

void	ft_beta(int kcode, t_var *var)
{
	int	res;

	if (kcode == 88)
	{
		var->infobeta -= 5;
		var->beta -= 5;
	}
	if (kcode == 86)
	{
		var->infobeta += 5;
		var->beta += 5;
	}
	if (var->infobeta > 360)
		var->infobeta = 5;
	if (var->infobeta < 0)
		var->infobeta = 355;
	res = mlx_clear_window(var->mlx, var->win);
	ft_transform(var);
	ft_drawlines(var);
}

void	ft_centr(t_var *var)
{
	int	res;

	var->alfa = 50;
	var->beta = 20;
	var->infobeta = var->beta;
	var->infoalpha = var->alfa;
	res = mlx_clear_window(var->mlx, var->win);
	ft_transform(var);
	ft_drawlines(var);
}

void	ft_angle(int kcode, t_var *var)
{
	if (kcode == 91 || kcode == 84)
		ft_alfa(kcode, var);
	if (kcode == 88 || kcode == 86)
		ft_beta(kcode, var);
	if (kcode == 87)
		ft_centr(var);
	ft_info(var);
}
