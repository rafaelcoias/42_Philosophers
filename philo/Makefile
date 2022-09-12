# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 23:32:46 by rade-sar          #+#    #+#              #
#    Updated: 2022/09/12 11:01:43 by rade-sar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########## 		   NAMES 		##########

NAME = philo

########## 		  SOURCES 		##########

SRC_PATH = ./src/

SRC = $(SRC_PATH)main.c	\
		$(SRC_PATH)check.c	\
		$(SRC_PATH)forks.c	\
		$(SRC_PATH)mutexes.c	\
		$(SRC_PATH)philos.c	\
		$(SRC_PATH)threads.c	\
		$(SRC_PATH)utils.c	\
		$(SRC_PATH)write_logs.c	\
		$(SRC_PATH)end_simulation.c	\
		$(SRC_PATH)routine.c		\

########## 		  INCLUDES 		##########

HEAD = ./include

########## 		   LIBFT 		##########

LIBFT = 

########## 		COMPILATION 	##########

OBJ = ${SRC:.c=.o}

CC = gcc

########## 		   FLAGS 		##########

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -pthread

########## 		   COLORS 		##########

GREEN		=	\033[0;32m
YELLOW	=	\033[0;33m
RED		=	\033[0;31m
BLUE_PISK		=	\033[0;34;5;199m
BLUE		=	\033[0;36m
VIOLET	=	\033[0;38;5;199m
RESET		=	\033[0m

########## 		  COMMANDS		##########

MAKE_LIBFT = 

CLEAN_LIBFT = 

FCLEAN_LIBFT = 

RM = rm -f

########## 		  MESSAGES 		##########

CREATE_PROJ_MSG = @echo "\n<========== $(GREEN)$(NAME) created$(RESET) ==========>\n"

CREATE_BONUS_MSG = @echo "\n<========== $(GREEN)$(BONUS) created$(RESET) ==========>\n"

REMOVED_MSG = @echo "\n<========== $(RED)$(NAME) removed$(RESET) ==========>\n"

NORM_LIBFT_MSG = @echo "\n<========== $(YELLOW)Norm $(LIBFT)$(RESET) ==========>\n"

NORM_PROJ_MSG = @echo "\n<========== $(YELLOW)Norm $(NAME)$(RESET) ==========>\n"

########## 		  TARGETS 		##########

${NAME}: ${OBJ} 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

${BONUS}: 

########## 		   RULES 		##########

all: ${NAME} 
	${CREATE_PROJ_MSG}

bonus:

clean:
	${RM} ${OBJ}

fclean: clean 
	${RM} ${NAME}
	${REMOVED_MSG}
	

re:	fclean all

norm:
	${NORM_PROJ_MSG}
	@cd ./src && norminette -R CheckForbiddenSourceHeader *.c && cd ../include && norminette -R CheckDefine *.h

.PHONY: all clean fclean re norm
