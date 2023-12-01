CLIENT_NAME = client
CLIENT_SRCS = client.c client_utils.c
CLIENT_OBJS = $(CLIENT_SRCS:%.c=%.o)
SERVER_NAME = server
SERVER_SRCS = server.c
SERVER_OBJS = $(SERVER_SRCS:%.c=%.o)
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM      =   rm -f
NAME    =   minitalk

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

$(NAME): $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $^ libft/libft.a -o $@

$(SERVER_NAME): $(SERVER_OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $^ libft/libft.a -o $@

clean:
	$(MAKE) -C ./libft clean
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)

fclean: clean
	$(RM) $(CLIENT_NAME) $(SERVER_NAME)

re:	fclean all

.PHONY:	all clean fclean re
