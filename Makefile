# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 15:38:08 by javigarc          #+#    #+#              #
#    Updated: 2022/11/28 16:40:23 by javigarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------ Sources ------------------------------

# Files

FDF			=	fdf.c \
				fdf_map.c \
				fdf_hooks.c \
				fdf_hooks_ctl.c \
				fdf_calculus.c \
				fdf_draw.c \
				fdf_draw_light.c \
				fdf_draw_rotations.c \
				fdf_color.c
			
# Sources and objects

FDF_SRC		=	$(FDF)

FDF_OBJS	=	$(FDF_SRC:.c=.o)

OBJS		=	$(FDF_OBJS)

# ------------------------------ Constant strings ------------------------------

GCC			=	gcc

FLAGS		=	-Wall -Wextra -Werror
#-g3 -fsanitize=address

NAME		=	fdf

LIBMK		=	cd mlx && make

LIBFTMK		=	cd libft && make

LIBS		=	-L mlx -lmlx -framework OpenGL -framework AppKit libft/libft.a
# ------------------------------ Rules ------------------------------

all: $(NAME)

$(NAME): $(FDF_OBJS)
	@$(LIBMK)
	@$(LIBFTMK)
	@$(GCC) $(FLAGS) $(FDF_OBJS) $(LIBS) -o $(NAME)
	
clean:
	rm -rf $(OBJS)
	make clean -C mlx/
	make clean -C libft/

fclean: clean
	rm -rf $(NAME)

.c.o:
	${GCC} ${FLAGS} $(INCLUDE) -c $< -o ${<:.c=.o}

re:	fclean all

.PHONY: all fdf clean fclean re
