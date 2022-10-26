NAME	= philo

SRCS	= ./main.c

CFLAGS	= -g -pthread -Wall -Werror -Wextra

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