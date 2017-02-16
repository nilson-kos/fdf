/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 20:47:46 by kshcherb          #+#    #+#             */
/*   Updated: 2017/02/15 20:56:57 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_ch_big(char **mass)
{
	int	x;
	int	max;

	x = 0;
	max = 0;
	while (mass[x] != NULL)
	{
		max++;
		x++;
	}
	max--;
	return (max);
}

void	ft_ch_smal(char **mass, int max)
{
	int	x;

	x = 0;
	while (mass[x] != NULL)
		x++;
	if (x <= max)
	{
		ft_putstr("lines must be equal\n");
		exit(0);
	}
}
