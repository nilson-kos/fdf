/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 19:24:59 by kshcherb          #+#    #+#             */
/*   Updated: 2017/02/12 19:37:27 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_list(t_coord *coord)
{
	t_coord	*tmp;

	tmp = coord;
	printf("\n");
	while (tmp != NULL)
	{		
			printf("z = %d, x = %d, y = %d, rgb = %d\n", tmp->z, tmp->x, tmp->y, tmp->rgb);
			tmp = tmp->next;
	}
}

int			main(int argc, char **argv)
{
	char 	*str;
	int		res;
	int		i;
	t_var	var;

	i = 0;

	if (argc != 2)
	{
		ft_putstr("usage: ./fdf <map_file>\n");
		return (0);
	}
	var = *(ft_readfile(argv[1]));
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 1200, 1200, "FdF by kos;");
	print_list(var.coord);
	ft_putnbr(var.may);
	ft_drawline(&var);
	mlx_loop(var.mlx);
	return (0);	
}
