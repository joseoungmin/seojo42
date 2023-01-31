# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 11:55:56 by seojo             #+#    #+#              #
#    Updated: 2023/01/31 16:29:19 by seojo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
DEPFLAGS		=	-MMD -MP -MF $(@:$(OBJ_DIR)%.o=$(DEP_DIR)%.d)
CPPFLAGS		=	-I$(LIBFT_DIR)$(INC_DIR)	\
					-I$(MLX_DIR) 				\
					-I$(INC_DIR)				\
					-I$(INC_DIR)$(PARSE_DIR)

RM				=	rm -rf
Q				=	@

LIBFT_DIR		=	libft/
MLX_DIR			=	mlx/
INC_DIR			=	include/
SRC_DIR			=	src/
OBJ_DIR			=	.obj/
DEP_DIR			=	.dep/
PARSE_DIR		=	map_parse/

PROG			=	"cub3D"
SRC_FILE		=	main.c								\
					init.c								\
					set_world.c							\
					set_player.c						\
					key_toggle.c						\
					move.c								\
					render_map.c						\
					safe_func.c							\
					free_map.c							\
					error.c								\
					ft_open.c							\
					$(addprefix $(PARSE_DIR), $(PARSE_FILE))

PARSE_FILE		=	check_argument.c		\
					check_map.c				\
					check_map_object.c		\
					check_map_file_color.c	\
					check_map_count_alloc.c	\
					check_eight_direction.c	\

OBJ_FILE		=	$(SRC_FILE:.c=.o)

LIBFT			=	$(LIBFT_DIR)libft.a
MLX				=	$(MLX_DIR)libmlx.a
SRCS			=	$(addprefix $(SRC_DIR), $(SRC_FILE))
OBJS			=	$(SRC_FILE:%.c=$(OBJ_DIR)%.o)
DEPS			=	$(SRC_FILE:%.c=$(DEP_DIR)%.d)

LDLIBS			=	$(LIBFT) $(MLX) -framework OpenGL -framework AppKit

ifdef DEBUG
	CFLAGS	+= -g -fsanitize=address,undefined	#-pedantic 
endif
ifdef PRINT
	Q			=
endif

-include $(DEPS)
.DEFAULT_GOAL	=	all

all				:	$(NAME)

$(NAME)			:	$(LIBFT) $(MLX) $(OBJS)
					$Q$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDLIBS)
					@echo "\033[K\033[32m   $(PROG) is Ready ✅\033[0m"

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c
					@mkdir -p $(OBJ_DIR)$(PARSE_DIR) $(DEP_DIR)$(PARSE_DIR)
					@echo "\033[K\033[32m   $(PROG) is Ready : $<\033[A"
					$Q$(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(LIBFT)		:	$(LIBFT_DIR)$(SRC_DIR) $(LIBFT_DIR)$(INC_DIR)
					@make -C $(LIBFT_DIR) all

$(MLX)			:	$(MLX_DIR)
					@make -s -C $(MLX_DIR) 2> /dev/null
					@echo "\033[K\033[33m     mlx is Ready ✅\033[0m"

clean			:
					$Qmake -C $(LIBFT_DIR) clean
					$Qmake -s -C $(MLX_DIR) clean
					$Q$(RM) $(OBJ_DIR) $(DEP_DIR)
					@echo "\033[36m  Remove Objects! 🗑\033[0m"

fclean			:	clean
					$Qmake -C $(LIBFT_DIR) fclean
					$Q$(RM) $(NAME)
					@echo "\033[96m  Remove Program! 🗑\033[0m"

re				:	fclean
					@make all

.PHONY			:	all clean fclean re