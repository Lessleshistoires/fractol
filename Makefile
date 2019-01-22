# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/11 14:31:05 by lpelissi          #+#    #+#              #
#    Updated: 2019/01/18 18:35:29 by lpelissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

CFLAGS = -Wall -Wextra -Werror -I $(IDIR) -I $(LIBFT)

IDIR = .
SDIR = .
ODIR = obj
LIBFT = libft
MLX = minilibx_macos

NAME = fractol

DEPS = $(IDIR)/fractol.h

INCL = -I $(MLX)

FRAM = -L $(MLX) -lmlx -framework OpenGL -framework AppKit

OBJ = $(patsubst %.c,$(ODIR)/%.o,$(_SRC))

SRC = $(patsubst %,$(SDIR)/%,$(_SRC)))

_SRC = main.c \
		ft_fractol.c \
		draw.c \
		other_draw.c \
		gere_key.c \
		gere_mouse.c \
		env_init.c \


.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)/libft.a
	cc $^ $(INCL) $(LIBFT)/libft.a -o $@ $(FRAM)

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	@mkdir -p $(dir $@)
	$(CC) -c -o $@ $< $(CFLAGS)

$(LIBFT)/libft.a:
	make -C libft/
	make -C minilibx_macos/

clean: cleanlib
	rm -f $(OBJ)

fclean:clean fcleanlib
	rm -f $(NAME)

re:fclean all

cleanlib:
	make clean -C libft/
	make clean -C minilibx_macos/

fcleanlib:
	make fclean -C libft/

relib:
	make re -C libft/
	make re -C minilibx_macos/
