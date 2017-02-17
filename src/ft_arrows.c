/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrows.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 20:53:03 by kshcherb          #+#    #+#             */
/*   Updated: 2017/02/17 21:07:43 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_key_barrow(t_var *var)
{
	int		res;
	t_coord	*tmp;

	tmp = var->coord;
	while (tmp != NULL)
	{
		tmp->y += 10;
		tmp = tmp->next;
	}
	res = mlx_clear_window(var->mlx, var->win);
	ft_drawlines(var);
}

void		ft_key_tarrow(t_var *var)
{
	int		res;
	t_coord	*tmp;

	tmp = var->coord;
	while (tmp != NULL)
	{
		tmp->y -= 10;
		tmp = tmp->next;
	}
	res = mlx_clear_window(var->mlx, var->win);
	ft_drawlines(var);
}

void		ft_key_larrow(t_var *var)
{
	int		res;
	t_coord	*tmp;

	tmp = var->coord;
	while (tmp != NULL)
	{
		tmp->x -= 10;
		tmp = tmp->next;
	}
	res = mlx_clear_window(var->mlx, var->win);
	ft_drawlines(var);
}

void		ft_key_rarrow(t_var *var)
{
	int		res;
	t_coord	*tmp;

	tmp = var->coord;
	while (tmp != NULL)
	{
		tmp->x += 10;
		tmp = tmp->next;
	}
	res = mlx_clear_window(var->mlx, var->win);
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
}
