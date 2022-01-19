# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 16:13:53 by dlanotte          #+#    #+#              #
#    Updated: 2021/07/28 17:43:36 by amarcell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOR_OFF	= "\033[0m"       # Text Reset
RED			= "\033[0;31m"    # Red
YELLOW		= "\033[0;33m"    # Yellow

NAME	=	minishell

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

LIBFT	=	minilibft/ft_split.c \
			minilibft/ft_utils_libft.c \
			minilibft/ft_path_utils.c \
			minilibft/ft_strjoin.c \
			minilibft/ft_calloc.c \
			minilibft/ft_bzero.c \
			minilibft/ft_memcpy.c \
			minilibft/ft_strlen.c \
			minilibft/ft_strcut.c\
			minilibft/ft_strcpy.c\
			minilibft/ft_itoa.c\
			minilibft/ft_putstr.c\
			minilibft/ft_strdigit.c\
			minilibft/ft_atoi.c	\
			minilibft/ft_strfind.c\
			minilibft/mat_row.c\
			minilibft/ft_stralpha.c\
			minilibft/mat_join_row.c\
			minilibft/mat_init.c	\
			minilibft/ft_lstadd_back.c	\
			minilibft/ft_lstadd_front.c	\
			minilibft/ft_lstclear.c	\
			minilibft/ft_lstdelone.c\
			minilibft/ft_lstiter.c	\
			minilibft/ft_lstlast.c	\
			minilibft/ft_lstnew.c	\
			minilibft/ft_lstsize.c	\
			minilibft/ft_matsort.c	\
			minilibft/mat_dup.c		\
			minilibft/ft_strcmp.c	\
			minilibft/ft_substr.c	\
			minilibft/ft_strtrim.c	\
			minilibft/ft_skip.c	\
			minilibft/ft_shint.c

GNL		= 	get_next_line/get_next_line.c \
			get_next_line/utils_gnl.c \
			get_next_line/cursor.c

GRAPH	=	graphic_functions/graphic_main.c

COMMAND	=	commands/easy_cmd.c\
			commands/env_cmd.c	\
			commands/env_cmd2.c	\
			commands/common_cmd.c\
			commands/utils.c

ENV		=	env/env_manager.c \
			env/env_util0.c

HISTORY	=	history/history.c	\
			history/history_utils.c

SRC		=	${ENV} ${GRAPH} ${GNL} ${LIBFT} ${COMMAND} ${HISTORY} main.c utils.c parsing.c \
			translate.c ft_dollar.c redirect.c parsing_utils.c matrix_arg.c main_utils.c	\
			parsing_utils2.c

OBJ := ${SRC:.c=.o}

%.o: %.c
	@ $(CC) $(CFLAGS) -g -c $< -o $@ 

all: $(NAME)

title:
	@ echo ""
	@ echo "   █████  ███████  ██████ ██ ██"$(RED)" ██░ ██ ▓█████  ██▓     ██▓     " $(COLOR_OFF)
	@ echo "  ██   ██ ██      ██      ██ ██"$(RED)"▓██░ ██▒▓█   ▀ ▓██▒    ▓██▒     " $(COLOR_OFF)
	@ echo "  ███████ ███████ ██      ██ ██"$(RED)"▒██▀▀██░▒███   ▒██░    ▒██░     " $(COLOR_OFF)
	@ echo "  ██   ██      ██ ██      ██ ██"$(RED)"░▓█ ░██ ▒▓█  ▄ ▒██░    ▒██░     " $(COLOR_OFF)
	@ echo "  ██   ██ ███████  ██████ ██ ██"$(RED)"░▓█▒░██▓░▒████▒░██████▒░██████▒ " $(COLOR_OFF)
	@ echo "                               "$(RED)" ▒ ░░▒░▒░░ ▒░ ░░ ▒░▓  ░░ ▒░▓  ░ " $(COLOR_OFF)
	@ echo "  amarcell | gcarbone | dlanotte"$(RED)"▒ ░▒░ ░ ░ ░  ░░ ░ ▒  ░░ ░ ▒  ░ " $(COLOR_OFF)
	@ echo "  flwang   | mobrycki | fd-agnes"$(RED)"░  ░░ ░   ░     ░ ░     ░ ░    " $(COLOR_OFF)
	@ echo "                               "$(RED)" ░  ░  ░   ░  ░    ░  ░    ░  ░ " $(COLOR_OFF)           
	@ echo ""
	@ read -p "Done. Press enter to continue..."

$(NAME): $(OBJ)
	@ echo $(RED)"Wait..."$(COLOR_OFF)
	@ $(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@ make title

clean:   
	@ rm -f ${OBJ}
	@ echo $(YELLOW)"clean completed."$(COLOR_OFF)

fclean: clean
	@ rm -f $(NAME)
	@ rm -f ${OBJ}
	@ rm -dir -f *.dSYM
	@ rm -f *.out
	@ rm -f .history
	@ find . -name ".DS_Store" -delete
	@ echo $(RED)"fclean completed."$(COLOR_OFF)

re: fclean
	@ make

norme:
		@ echo $(BBLUE) "-------|norme $(NAME)|-------" $(COLOR_OFF) $(BLUE)
		@ norminette $(SRC)
		@ norminette includes/*.h
		@ echo $(COLOR_OFF)

.PHONY: 	all clean fclean re norme 