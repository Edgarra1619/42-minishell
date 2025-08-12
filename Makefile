NAME = minishell
SRCS = main.c error.c echo.c pwd.c cd.c export.c unset.c env.c exec.c path.c \
	   fd.c startup.c syntax.c big_tokenizer.c
INCDIR = ./include/
SRCDIR = ./src/
OBJDIR = ./obj/
LFTDIR = ./libft/

CC = cc
CFLAGS = -Wall -Wextra -gdwarf-4 $(INCFLAGS)
INCFLAGS = -I $(INCDIR) -I $(LFTDIR)/include/
LIBFLAGS = -lreadline

OBJS = $(patsubst %.c, $(OBJDIR)%.o, $(SRCS))
LFT = $(LFTDIR)/libft.a

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -fr $(OBJDIR)

fclean: clean
	rm -f $(NAME)
	make $@ -C $(LFTDIR)

re: clean all

$(NAME): $(OBJS) $(LFT)
	$(CC) $(CFLAGS) $(LIBFLAGS) -o $@ $^

$(OBJS): $(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ -c $<

$(LFT):
	make -C $(LFTDIR)
