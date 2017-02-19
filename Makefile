# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kshcherb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/19 17:36:18 by kshcherb          #+#    #+#              #
#    Updated: 2017/02/19 17:39:45 by kshcherb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

IDIR = includes/

VPATH = src:includes

FLAGS = -O3 -Wall -Wextra -Werror -I$(IDIR)

MLX = -lmlx -framework AppKit -framework OpenGl

LIB = libft/libft.a

SRCS =		main.c											\
			ft_angle.c										\
			ft_arrows.c										\
			ft_check_valid.c								\
			ft_drawlines.c									\
			ft_key_events.c									\
			ft_put_info.c									\
			ft_readfile.c									\
			ft_rgb.c										\
			ft_transform.c									\
			ft_up_down_z.c									\
			ft_zoom.c										\

BINS = $(SRCS:.c=.o)

all: $(NAME)

makelib:
	make -C libft/

libclean:
	make -C libft/ clean

libfclean:
	make -C libft/ fclean

$(NAME): $(BINS)
	make -C libft/
	gcc -o $(NAME) $(BINS) $(FLAGS) $(MLX) $(LIB)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean: libclean
	/bin/rm -f $(BINS)

fclean: libfclean clean
	/bin/rm -f $(NAME)

re: fclean all
