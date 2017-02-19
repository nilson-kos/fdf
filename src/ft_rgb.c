/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 16:58:11 by kshcherb          #+#    #+#             */
/*   Updated: 2017/02/19 17:40:53 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_default(t_var *var)
{
	t_coord	*tmp;
	int		res;

	tmp = var->coord;
	while (tmp != NULL)
	{
		tmp->rgb = tmp->rgb0;
		tmp = tmp->next;
	}
	res = mlx_clear_window(var->mlx, var->win);
	ft_drawlines(var);
}

void		ft_red(t_var *var)
{
	t_coord	*tmp;
	int		res;

	tmp = var->coord;
	while (tmp != NULL)
	{
		tmp->rgb = 0xFF0000;
		tmp = tmp->next;
	}
	res = mlx_clear_window(var->mlx, var->win);
	ft_drawlines(var);
}

void		ft_green(t_var *var)
{
	t_coord	*tmp;
	int		res;

	tmp = var->coord;
	while (tmp != NULL)
	{
		tmp->rgb = 0x00FF00;
		tmp = tmp->next;
	}
	res = mlx_clear_window(var->mlx, var->win);
	ft_drawlines(var);
}

void		ft_blue(t_var *var)
{
	t_coord	*tmp;
	int		res;

	tmp = var->coord;
	while (tmp != NULL)
	{
		tmp->rgb = 0x0000FF;
		tmp = tmp->next;
	}
	res = mlx_clear_window(var->mlx, var->win);
	ft_drawlines(var);
}

void		ft_rgb(int kcode, t_var *var)
{
	if (kcode == 49)
		ft_default(var);
	if (kcode == 15)
		ft_red(var);
	if (kcode == 5)
		ft_green(var);
	if (kcode == 11)
		ft_blue(var);
	ft_info(var);
}
