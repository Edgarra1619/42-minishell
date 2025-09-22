NAME = minishell
SRCS = main.c error.c exit.c env.c env2.c var.c pipeline.c cmd.c exec.c path.c fd.c \
	   syntax.c signals.c \
	   tokenizer/pipeline_tokenizer.c tokenizer/cmd_tokenizer.c \
	   tokenizer/parse_expansions.c tokenizer/parse_whtspc.c \
	   tokenizer/parse_redirs.c tokenizer/parse_quotes.c tokenizer/heredoc.c \
	   builtins/unset.c builtins/export.c builtins/exit.c \
	   builtins/echo.c builtins/cd.c builtins/pwd.c \
	   builtins/env.c
INCDIR = ./include/
SRCDIR = ./src/
OBJDIR = ./obj/
LFTDIR = ./libft/

CC = cc
CFLAGS = -Wall -Wextra -gdwarf-4 $(INCFLAGS)
INCFLAGS = -I $(INCDIR) -I $(LFTDIR)/include/
LIBFLAGS = -lreadline

VALGFLAGS = --track-origins=yes --leak-check=full --show-leak-kinds=all \
			--suppressions=readline.supp

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
	mkdir -p $(OBJDIR) $(OBJDIR)/builtins $(OBJDIR)/tokenizer
	$(CC) $(CFLAGS) -o $@ -c $<

test: $(NAME)
	./$(NAME)

gprof: $(NAME)
	./$(NAME)
	rm gprof-output -f
	gprof $(NAME) > gprof-output

valgrind: $(NAME)
	valgrind $(VALGFLAGS) ./$(NAME)

gdb: $(NAME)
	gdbtui $(NAME)

vgdb: $(NAME)
	valgrind $(VALGFLAGS) --vgdb=full --vgdb-error=0 ./$(NAME)

$(LFT):
	make -C $(LFTDIR)
