# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nschat <nschat@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/30 12:13:23 by nschat        #+#    #+#                  #
#    Updated: 2019/10/30 13:33:57 by nschat        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -g -Wall -Wextra -Werror -Iinclude -Ilibft/include

SRC = main.c test_str.c test_mem.c test_misc.c

ODIR = obj
OBJ = $(addprefix $(ODIR)/,$(SRC:.c=.o))

LIB = libft/libft.a

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

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(dir $(LIB)) fclean

re: fclean all
