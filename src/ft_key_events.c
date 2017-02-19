/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 20:48:08 by kshcherb          #+#    #+#             */
/*   Updated: 2017/02/19 15:13:36 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_key_events(int kcode, t_var *var)
{
	if (kcode == 53)
		exit(0);
	if (kcode >= 123 && kcode <= 126)
		ft_arrows(kcode, var);
	if (kcode == 27 || kcode == 24)
		ft_zoom(kcode, var);
	if (kcode == 91 || kcode == 88 || kcode == 84 || kcode == 86 || kcode == 87)
		ft_angle(kcode, var);
	if (kcode == 49 || kcode == 15 || kcode == 5 || kcode == 11)
		ft_rgb(kcode, var);
	if (kcode == 43 || kcode == 47 || kcode == 34)
		ft_up_down_z(kcode, var);
	return (0);
}
