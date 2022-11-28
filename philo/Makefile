# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 09:13:28 by fesper-s          #+#    #+#              #
#    Updated: 2022/11/28 14:19:49 by fesper-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

SRCS	= ./main.c ./utils.c ./philo.c ./mutex.c

CFLAGS	= -pthread -Wall -Werror -Wextra

OBJS	= $(SRCS:.c=.o)

$(NAME):	$(OBJS)
			cc $^ $(CFLAGS) -o $@

all:		$(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re