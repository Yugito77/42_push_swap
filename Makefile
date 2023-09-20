# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 15:51:01 by hcherpre          #+#    #+#              #
#    Updated: 2022/01/13 19:46:47 by hcherpre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = push_swap

CC     = gcc

LINKER     = ar rcs

RM     = rm -rf

SRCS     =  check.c ft_atol.c ft_split.c\
			op.c push_swap_utils1.c push_swap_utils2.c\
			radix.c small_sorted.c push_swap.c

OBJS        = ${SRCS:.c=.o}

CFLAGS     = -Wall -Wextra -Werror

$(NAME): ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all:    ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re:    fclean all