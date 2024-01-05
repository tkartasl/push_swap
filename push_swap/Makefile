# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkartasl <tkartasl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 14:42:20 by tkartasl          #+#    #+#              #
#    Updated: 2024/01/04 08:29:45 by tkartasl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = srcs/push_swap.c\
		srcs/array_utils.c \
		srcs/rules.c \
		srcs/rules_reverse_rotate.c \
		srcs/stack_utils.c \
		srcs/utils.c \
		srcs/sort.c

LIBFT = Libft/

LIBFT_A = Libft/libft.a 

MAKE = make 

FLAGS = -Wall -Wextra -Werror -I includes

CC = cc 

all: ${NAME}

${NAME}: ${SRCS}
	${MAKE} all -C ${LIBFT}
	${CC} ${FLAGS} ${SRCS} ${LIBFT_A} -o ${NAME}
	
clean:
	${MAKE} clean -C ${LIBFT}

fclean: clean
	rm -f ${NAME}
	${MAKE} fclean -C ${LIBFT}

re: fclean all	