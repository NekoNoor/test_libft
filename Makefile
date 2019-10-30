# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nschat <nschat@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/30 12:13:23 by nschat        #+#    #+#                  #
#    Updated: 2019/10/30 12:22:15 by nschat        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

LIB = libft/libft.a

CC = clang
CFLAGS = -g -Wall -Wextra -Werror -Iinclude -I$(dir $(LIB))include

SRC = main.c

ODIR = obj
OBJ = $(addprefix $(ODIR)/,$(SRC:.c=.o))

NAME = test_libft

vpath %.c src

.PHONY: clean fclean

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(LIB):
	$(MAKE) -C $(dir $(LIB))

$(ODIR):
	mkdir -p $@

$(ODIR)/%.o: %.c $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(ODIR)
	$(MAKE) -C $(dir $(LIB)) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(dir $(LIB)) fclean

re: fclean all
