# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 12:10:14 by rade-sar          #+#    #+#              #
#    Updated: 2022/04/26 11:48:17 by rade-sar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########## 		   NAMES 		##########

NAME = libft.a

########## 		  SOURCES 		##########

LIBFT_PATH = ./library/

PRINT_F_PATH = ./ft_printf/

GNL_PATH = ./get_next_line/

SRC = 	$(LIBFT_PATH)ft_isalpha.c	\
		$(LIBFT_PATH)ft_isdigit.c	\
		$(LIBFT_PATH)ft_strcmp.c	\
		$(LIBFT_PATH)ft_isascii.c	\
		$(LIBFT_PATH)ft_isalnum.c	\
		$(LIBFT_PATH)ft_isprint.c	\
		$(LIBFT_PATH)ft_atoi.c 		\
		$(LIBFT_PATH)ft_memcpy.c 	\
		$(LIBFT_PATH)ft_bzero.c 	\
		$(LIBFT_PATH)ft_strlen.c 	\
		$(LIBFT_PATH)ft_memset.c 	\
		$(LIBFT_PATH)ft_strchr.c 	\
		$(LIBFT_PATH)ft_strlcat.c 	\
		$(LIBFT_PATH)ft_strcpy.c	\
		$(LIBFT_PATH)ft_strlcpy.c 	\
		$(LIBFT_PATH)ft_tolower.c 	\
		$(LIBFT_PATH)ft_toupper.c 	\
		$(LIBFT_PATH)ft_strncmp.c 	\
		$(LIBFT_PATH)ft_strnstr.c 	\
		$(LIBFT_PATH)ft_strrchr.c 	\
		$(LIBFT_PATH)ft_memcmp.c 	\
		$(LIBFT_PATH)ft_memchr.c 	\
		$(LIBFT_PATH)ft_memmove.c 	\
		$(LIBFT_PATH)ft_calloc.c 	\
		$(LIBFT_PATH)ft_strdup.c 	\
		$(LIBFT_PATH)ft_substr.c 	\
		$(LIBFT_PATH)ft_strjoin.c 	\
		$(LIBFT_PATH)ft_strtrim.c 	\
		$(LIBFT_PATH)ft_split.c 	\
		$(LIBFT_PATH)ft_itoa.c 		\
		$(LIBFT_PATH)ft_strmapi.c 	\
		$(LIBFT_PATH)ft_striteri.c 	\
		$(LIBFT_PATH)ft_putchar_fd.c	\
		$(LIBFT_PATH)ft_putstr_fd.c 	\
		$(LIBFT_PATH)ft_putendl_fd.c	\
		$(LIBFT_PATH)ft_putnbr_fd.c		\
		$(LIBFT_PATH)ft_atol.c 			\
		$(LIBFT_PATH)ft_lstnew.c 		\
		$(LIBFT_PATH)ft_lstadd_front.c	\
		$(LIBFT_PATH)ft_lstadd_front.c 	\
		$(LIBFT_PATH)ft_lstsize.c 		\
		$(LIBFT_PATH)ft_lstlast.c 		\
		$(LIBFT_PATH)ft_lstadd_back.c	\
		$(LIBFT_PATH)ft_lstdelone.c 	\
		$(LIBFT_PATH)ft_lstclear.c 		\
		$(LIBFT_PATH)ft_lstiter.c 		\
		$(LIBFT_PATH)ft_lstmap.c		\
		$(LIBFT_PATH)ft_power_to.c		\
		$(LIBFT_PATH)ft_sqrt.c			\
		$(GNL_PATH)/get_next_line.c			\
		$(GNL_PATH)/get_next_line_utils.c	\
		$(PRINT_F_PATH)/ft_printf.c			\
		$(PRINT_F_PATH)/ft_putchar.c		\
		$(PRINT_F_PATH)/ft_putstr.c			\
		$(PRINT_F_PATH)/ft_putnbr.c			\
		$(PRINT_F_PATH)/ft_puthexa.c		\
		$(PRINT_F_PATH)/ft_putvoid.c		\

########## 		  INCLUDES 		##########

HEAD = ./

########## 		COMPILATION 	##########

OBJ = ${SRC:.c=.o}

CC = gcc

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEAD}

########## 		   FLAGS 		##########

CFLAGS = -Wall -Wextra -Werror

########## 		   COLORS 		##########

GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
RED			=	\033[0;31m
RESET       =   \033[0m

########## 		  COMMANDS		##########

RM = rm -f

AR = ar rc

RANLIB = ranlib

########## 		  MESSAGES 		##########

NORM_LIBFT_MSG = @echo "\n<========== $(YELLOW)Norm $(NAME)$(RESET) ==========>\n"

CREATE_LIBFT_MSG = @echo "\n<========== $(GREEN)$(NAME) created$(RESET) ==========>\n"

REMOVE_LIBFT_MSG = @echo "\n<========== $(RED)$(NAME) removed$(RESET) ==========>\n"

########## 		  TARGETS 		##########

${NAME}: ${OBJ}
	${AR} ${NAME} ${OBJ}
	${RANLIB} ${NAME}

########## 		   RULES 		##########

all: ${NAME}
	${CREATE_LIBFT_MSG}

clean: 
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}
	${REMOVE_LIBFT_MSG}

re:	fclean all

norm:
	${NORM_LIBFT_MSG}
	@cd ${LIBFT_PATH} && norminette -R CheckForbiddenSourceHeader *.c && norminette -R CheckDefine *.h
	@echo "\n"
	@cd ${PRINT_F_PATH} && norminette -R CheckForbiddenSourceHeader *.c && norminette -R CheckDefine *.h
	@echo "\n"
	@cd ${GNL_PATH} && norminette -R CheckForbiddenSourceHeader *.c && norminette -R CheckDefine *.h

.PHONY: all clean fclean re norm
