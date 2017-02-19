/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 19:32:56 by kshcherb          #+#    #+#             */
/*   Updated: 2017/02/19 17:45:10 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_info(t_var *var)
{
	mlx_string_put(var->mlx, var->win, 5, 130, 0xFFFFFF, ft_strjoin("zoom "
	, "= "));
	mlx_string_put(var->mlx, var->win, 75, 130, 0xFFFFFF, ft_strjoin(
	ft_itoa(var->infozoom), "%"));
	mlx_string_put(var->mlx, var->win, 5, 147, 0xFFFFFF, ft_strjoin("alpha = "
	, ft_itoa(var->infoalpha)));
	mlx_string_put(var->mlx, var->win, 5, 164, 0xFFFFFF, ft_strjoin("beta = "
	, ft_itoa(var->infobeta)));
	mlx_string_put(var->mlx, var->win, 5, 181, 0xFFFFFF, ft_strjoin("z = "
	, ft_itoa(var->upz)));
	mlx_string_put(var->mlx, var->win, 5, 198, 0xFFFFFF, ft_strjoin(
	"projection = ", (var->alfa == 45 && var->beta == 35) ? "iso"
	: "parallel"));
	mlx_string_put(var->mlx, var->win, 5, 215, 0xFFFFFF, ft_strjoin("for iso "
	, "press i"));
}

void	ft_info(t_var *var)
{
	mlx_string_put(var->mlx, var->win, 5, 11, 0xFF0000, ft_strjoin("use arrows"
	, " for move and + - for zoom"));
	mlx_string_put(var->mlx, var->win, 5, 28, 0xFF8700, ft_strjoin("for change"
	, " angles use 4, 8, 6, 2"));
	mlx_string_put(var->mlx, var->win, 5, 45, 0xFBFF00, ft_strjoin("for return"
	, " to normal angles press 5"));
	mlx_string_put(var->mlx, var->win, 5, 62, 0x36FF00, ft_strjoin("if you like"
	, " red press r"));
	mlx_string_put(var->mlx, var->win, 5, 79, 0x00FFF7, ft_strjoin("b for blue"
	, " and g for green"));
	mlx_string_put(var->mlx, var->win, 5, 96, 0x0000FF, ft_strjoin("for normal"
	, " color press space"));
	mlx_string_put(var->mlx, var->win, 5, 113, 0xAE06BC, ft_strjoin("for change"
	, " z use < and >"));
	ft_put_info(var);
}
