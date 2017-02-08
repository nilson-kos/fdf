/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 19:24:59 by kshcherb          #+#    #+#             */
/*   Updated: 2017/02/08 20:49:42 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	char 	*str;
	int		res;
	int		i;	

	i = 0;

	if (argc != 2)
	{
		ft_putstr("usage: ./fdf <map_file>\n");
		return (0);
	}
	res = ft_readfile(argv[1]);	
	return (0);	
}
