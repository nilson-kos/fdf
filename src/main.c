/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 19:24:59 by kshcherb          #+#    #+#             */
/*   Updated: 2017/02/16 16:38:18 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_list(t_coord *coord)
{
	t_coord	*tmp;

	tmp = coord;
	printf("=========================================\n");
	while (tmp != NULL)
	{		
			printf("z = %d, x = %d, y = %d, rgb = %d\n", tmp->z, tmp->x, tmp->y, tmp->rgb);
			tmp = tmp->next;
	}
	printf("=========================================\n");
}

int			main(int argc, char **argv)
{
	char	*str;
	int		res;
	t_var	var;

	if (argc != 2)
	{
		ft_putstr("usage: ./fdf <map_file>\n");
		return (0);
	}
	var = *(ft_readfile(argv[1]));
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 1200, 1200, "FdF by kos;");
	//print_list(var.coord);
	//ft_putnbr(var.max);
	//ft_putchar('\n');
	//ft_putnbr(var.may);
	var = *(ft_transform(&var));
	ft_drawlines(&var);
	print_list(var.coord);
	mlx_loop(var.mlx);
	return (0);
}
