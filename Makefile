# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fepennar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 19:57:37 by fepennar          #+#    #+#              #
#    Updated: 2025/03/12 19:57:39 by fepennar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR	=	src/

SRC			=	init.c \
	create_map.c \
	mapdup.c \
	enemyfunc.c \
	check_map.c \
	convimage.c \
	moves.c \
	main.c \
	loopnhook.c \
	mapfill.c \
	power_off.c \
	floodfill.c \
	print_elements.c

SRCS		=	$(addprefix $(SRCS_DIR), $(SRC))

OBJS_DIR	=	obj/

OBJS		=	$(addprefix $(OBJS_DIR), $(SRC:.c=.o))

NAME		=	so_long

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g

RM			=	rm -f

INCLUDES	=	-I/usr/include -Imlx_linux -Ilibft

MLX_FLAGS	=	-Lmlx_linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz

LIBFT_FLAGS	=	-Llibft -lft

all:			$(NAME)

$(OBJS_DIR):
				mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c | $(OBJS_DIR)
				$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(NAME):		$(OBJS_DIR) $(OBJS)
				@make -C ./mlx_linux
				@make -C ./libft
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS)

clean:
				$(RM) $(OBJS)
				$(RM) -r $(OBJS_DIR)
				@make -C ./mlx_linux clean
				@make -C ./libft clean

fclean:			clean
				$(RM) $(NAME)
				@make -C ./libft fclean

re:				fclean all

norm:
				@norminette $(SRCS) $(SRCS_DIR)so_long.h

#test:			all
#				@./$(NAME) ./maps/test1.ber

#bonus:			all
#				@./$(NAME) ./maps/enemy_map.ber

.PHONY:			all clean fclean re norm test bonus
