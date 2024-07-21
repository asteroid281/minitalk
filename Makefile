SRC_SRV = server.c
SRC_CLT = client.c

SRV =	server
CLT =	client

PRINTFPATH = ft_printf/
PRINTF = $(PRINTFPATH)libftprintf.a
NAME = minitalk
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: ${NAME}

$(NAME): $(SRV) $(CLT)

$(PRINTF):
	make -C $(PRINTFPATH)

$(SRV): $(PRINTF) $(SRC_SRV)
	cc $(CFLAGS) $(SRC_SRV) -L $(PRINTFPATH) -l ftprintf -o $(SRV)

$(CLT): $(PRINTF) $(SRC_CLT)
	cc $(CFLAGS) $(SRC_CLT) -L $(PRINTFPATH) -l ftprintf -o $(CLT)

clean:
	make -C $(PRINTFPATH) clean
	${RM} ${SRV} ${CLT}

fclean: clean
	$(RM) $(PRINTF)

re: fclean all

.PHONY: all clean fclean re
