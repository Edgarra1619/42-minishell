NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -g $(INCFLAGS)
INCFLAGS = -I $(INCDIR) -I $(LFTDIR)$(INCDIR)
INCDIR = include/
SRCDIR = src/
SRC = minishell.c
SRCS = $(patsubst %, $(SRCDIR)%, $(SRC))
OBJDIR = obj/
OBJS = $(patsubst %.c, $(OBJDIR)%.o, $(SRC))
LFTDIR = libft/
LFT = $(patsubst %, $(LFTDIR)%, libft.a)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -fr $(OBJDIR)
	make $@ -C $(LFTDIR)

fclean: clean
	rm -f $(NAME)
	make $@ -C $(LFTDIR)

re: fclean all

$(NAME): $(OBJS) $(LFT)
	$(CC) $(CFLAGS) -lreadline -o $@ $^

$(OBJS): $(SRCS)
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ -c $<

$(LFT):
	make -C $(LFTDIR)
