/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 20:48:08 by kshcherb          #+#    #+#             */
/*   Updated: 2017/02/17 21:09:31 by kshcherb         ###   ########.fr       */
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
	return (0);
}
