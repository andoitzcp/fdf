# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acampo-p <acampo-p@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 09:35:35 by acampo-p          #+#    #+#              #
#    Updated: 2023/01/19 09:44:01 by acampo-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME		= fdf
INCLUDE		= include
LIBFT		= libft
FT_PRINTF	= ft_printf
MLX			= minilibx-linux
SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I$(INCLUDE)
RM			= rm -f

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources

SRC_FILES	=	main


SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

###

OBJF		=	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJ) $(LIBFT) $(FT_PRINTF) $(MLX)
			@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -L$(FT_PRINTF) -lftp -L$(MLX) -lmlx -lm -o $(NAME)
			@echo "$(GREEN)fdf compiled!$(DEF_COLOR)"

$(LIBFT):
			@$(MAKE) -s -C $(LIBFT)
			@echo "Compiled $(LIBFT).a"
$(FT_PRINTF):
			@$(MAKE) -s -C $(FT_PRINTF)
			@echo "Compiled $(FT_PRINTF).a"
$(MLX):
			@$(MAKE) -s -C $(MLX)
			@echo "Compiled libmlx_Linux.a"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) -rf $(OBJ_DIR)
			@$(MAKE) clean -C $(LIBFT)
			@$(MAKE) clean -C $(FT_PRINTF)
			@$(MAKE) clean -C $(MLX)
			@echo "$(BLUE)$(NAME) object files succesfully cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@echo "$(CYAN)$(NAME) executable files succesfully cleaned!$(DEF_COLOR)"
			@$(RM) -f $(LIBFT)/libft.a
			@echo "$(CYAN)$(LIBFT) executable files succesfully cleaned!$(DEF_COLOR)"
			@$(RM) -f $(FT_PRINTF)/$(FT_PRINTF).a
			@echo "$(CYAN)$(FT_PRINTF) executable files succesfully cleaned!$(DEF_COLOR)"
			@$(RM) -f $(MLX)/libmlx_Linux.a
			@echo "$(CYAN)$(MLX) executable files succesfully cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Everything was cleaned and the rebuilt for ft_printf!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(INCLUDE) $(LIBFT) $(FT_PRINTF) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm
