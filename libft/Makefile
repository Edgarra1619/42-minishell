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
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  ft_isspace.c ft_strlen.c ft_max.c ft_min.c ft_abs.c ft_clamp.c \
	  ft_sign.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	  ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	  ft_strrchr.c ft_strcmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	  ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
	  ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
	  ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	  ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_strappend.c \
	  ft_realloc.c
INCDIR = ./include/
SRCDIR = ./src/
OBJDIR = ./obj/

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INCDIR)
AR = ar
ARFLAGS = rc

OBJS = $(patsubst %.c, $(OBJDIR)%.o, $(SRCS))

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -fr $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: clean all

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJS): $(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ -c $<
