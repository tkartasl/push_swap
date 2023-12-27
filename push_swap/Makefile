# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkartasl <tkartasl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 14:42:20 by tkartasl          #+#    #+#              #
#    Updated: 2023/12/27 16:31:18 by tkartasl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = 

OBJS = ${SRCS:.c=.o}

LIBFT = /Libft

LIBFT_A = /Libft/libft.a 

MAKE = make 

FLAGS = -Wall -Wextra -Werror

CC = cc 

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${FLAGS} -o ${NAME} ${LIBFT_A}

${OBJS}: ${SRCS}
	${CC} ${FLAGS} -c ${SRCS}
	${MAKE} all -C ${LIBFT}

clean:
	rm -f ${OBJS}
	${MAKE} clean -C ${LIBFT}

fclean: clean
	rm -f ${NAME}
	${MAKE} fclean -C ${LIBFT}

re: fclean all	