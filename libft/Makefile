# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-albu <vde-albu@student.42porto.oom>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/29 11:48:01 by vde-albu          #+#    #+#              #
#    Updated: 2025/07/29 11:48:04 by vde-albu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INCDIR)
AR = ar
ARFLAGS = rc
INCDIR = include/
SRCDIR = src/
OBJDIR = obj/
OBJ = ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o \
	  ft_isspace.o ft_strlen.o ft_max.o ft_min.o ft_abs.o ft_clamp.o \
	  ft_sign.o ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o \
	  ft_strlcpy.o ft_strlcat.o ft_toupper.o ft_tolower.o ft_strchr.o \
	  ft_strrchr.o ft_strcmp.o ft_memchr.o ft_memcmp.o ft_strnstr.o \
	  ft_atoi.o ft_calloc.o ft_strdup.o ft_substr.o ft_strjoin.o ft_strtrim.o \
	  ft_split.o ft_itoa.o ft_strmapi.o ft_striteri.o ft_putchar_fd.o \
	  ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_lstnew.o \
	  ft_lstadd_front.o ft_lstsize.o ft_lstlast.o ft_lstadd_back.o \
	  ft_lstdelone.o ft_lstclear.o ft_lstiter.o ft_lstmap.o
OBJS = $(patsubst %, $(OBJDIR)%, $(OBJ))

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -fr $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJS): $(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ -c $<
