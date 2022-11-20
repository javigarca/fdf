# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 15:38:08 by javigarc          #+#    #+#              #
#    Updated: 2022/07/13 15:38:18 by javigarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------ Sources ------------------------------

# Files

FDF			=	fdf.c \
				fdf_map.c \
				fdf_hooks.c \
				fdf_calculus.c \
				fdf_draw.c \
				fdf_draw_light.c \
			
FDF_B		=	fdf_bonus.c

# Sources and objects

FDF_SRC		=	$(FDF)

FDF_OBJS	=	$(FDF_SRC:.c=.o)

FDF_B_SRC	=	$(FDF_B)

FDF_B_OBJS	=	$(FDF_B_SRC:.c=.o)

OBJS		=	$(FDF_OBJS) \
				$(FDF_B_OBJS) 

# ------------------------------ Constant strings ------------------------------

GCC			=	gcc

FLAGS		=	-Wall -Wextra -Werror -g3 -fsanitize=address
#-g3 -fsanitize=address

INCLUDE		=	-I include

FDF_NAME	=	fdf

FDF_B_NAME	=	fdf_bonus

NAME		=	fdf

LIBMK		=	cd mlx && make

LIBFTMK		=	cd libft && make

LIBS		=	-Lmlx -lmlx -framework OpenGL -framework AppKit libft/libft.a
# ------------------------------ Rules ------------------------------

all: $(NAME)

$(NAME): fdfa

bonus: fdfb
		 
fdfa: $(FDF_OBJS)
	$(LIBMK)
	$(LIBFTMK)
	$(GCC) $(FLAGS) $(FDF_OBJS) $(LIBS) -o $(FDF_NAME)
	
fdfb: $(FDF_B_OBJS)
	$(LIBMK)
	$(LIBFTMK)
	$(GCC) $(FLAGS) $(FDF_B_OBJS) $(LIBS) -o $(FDF_B_NAME)

clean:
	rm -rf $(OBJS)
	make clean -C mlx/
	make clean -C libft/

fclean: clean
	rm -rf $(FDF_NAME) $(FDF_B_NAME)

.c.o:
	${GCC} ${FLAGS} $(INCLUDE) -c $< -o ${<:.c=.o}

re:	fclean all

.PHONY: all fdf clean fclean re fdf_bonus minilibx
