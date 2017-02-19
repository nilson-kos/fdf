/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 19:24:59 by kshcherb          #+#    #+#             */
/*   Updated: 2017/02/19 18:36:20 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int argc, char **argv)
{
	t_var	var;

	if (argc != 2)
	{
		ft_putstr("usage: ./fdf <map_file>\n");
		return (0);
	}
	var = *(ft_readfile(argv[1]));
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 1200, 1200, "FdF by kos;");
	var = *(ft_transform(&var));
	ft_drawlines(&var);
	ft_info(&var);
	mlx_key_hook(var.win, ft_key_events, &var);
	mlx_loop(var.mlx);
	return (0);
}
