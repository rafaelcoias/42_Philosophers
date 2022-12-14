# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 23:32:46 by rade-sar          #+#    #+#              #
#    Updated: 2022/09/13 21:04:21 by rade-sar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########## 		   NAMES 		##########

NAME = philo

BONUS =

########## 		  SOURCES 		##########

SRC_PATH = ./src/

OBJ_DIR = objs

OBJ_PATH = $(OBJ_DIR)/

SRC = $(SRC_PATH)main.c	\
		$(SRC_PATH)check.c	\
		$(SRC_PATH)mutexes.c	\
		$(SRC_PATH)philos.c	\
		$(SRC_PATH)threads.c	\
		$(SRC_PATH)utils.c	\
		$(SRC_PATH)write_logs.c	\
		$(SRC_PATH)end_simulation.c	\
		$(SRC_PATH)routine.c		\

BNS =

########## 		  INCLUDES 		##########

HEAD = ./

########## 		   LIBFT 		##########

LIBFT = 

########## 		COMPILATION 	##########

OBJ = $(patsubst %.c, %.o, $(subst $(SRC_PATH), $(OBJ_PATH), $(SRC)))

CC = gcc

########## 		   FLAGS 		##########

CFLAGS = -Wall -Wextra -Werror -g

THR_FLAGS = -fsanitize=thread -pthread

MLC_FLAGS = -fsanitize=address

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

RM = rm -rf

########## 		  MESSAGES 		##########

CREATE_PROJ_MSG = @echo "\n[ $(GREEN)$(NAME) created$(RESET) ]\n"

REMOVED_MSG = @echo "\n[ $(RED)$(NAME) removed$(RESET) ]\n"

NORM_LIBFT_MSG = @echo "\n<========== $(YELLOW)Norm $(LIBFT)$(RESET) ==========>\n"

NORM_PROJ_MSG = @echo "\n<========== $(YELLOW)Norm $(NAME)$(RESET) ==========>\n"

NORM_CORRECT = @echo "\nNorminette: [$(GREEN)OK$(RESET)]\n"

########## 		  TARGETS 		##########

${NAME}: ${OBJ_DIR} ${OBJ}
	$(CC) $(CFLAGS) $(THR_FLAGS) -o $(NAME) $(OBJ)

${BONUS}: 

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(HEAD) -c $(^) -o $(@)
	@echo "$(YELLOW)[ Compiling $(subst .o,.c,$(notdir $@)) ]$(RESET)"

########## 		   RULES 		##########

all: ${NAME} 
	${CREATE_PROJ_MSG}

bonus:

clean:
	${RM} ${OBJ_PATH}

fclean: clean 
	${RM} ${NAME}
	${REMOVED_MSG}

re:	fclean all

norm:
	${NORM_PROJ_MSG}
	@cd ./src && norminette -R CheckForbiddenSourceHeader *.c
	@norminette -R CheckDefine philo.h
	${NORM_CORRECT}

.SILENT: ${OBJ} ${NAME} ${OBJ_DIR} clean fclean

.PHONY: all clean fclean re norm
