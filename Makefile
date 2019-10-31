# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nschat <nschat@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/30 12:13:23 by nschat        #+#    #+#                  #
#    Updated: 2019/10/31 17:00:57 by nschat        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -g -Wall -Wextra -Werror -I include -I libft/include \
		 -isystem ${BREW}/include
LDFLAGS = -L ${BREW}/lib -lcriterion

SRC = test_mem.c test_misc.c test_str.c

ODIR = obj
OBJ = $(addprefix $(ODIR)/,$(SRC:.c=.o))

LIB = libft/libft.a

NAME = test_libft

vpath %.c src

.PHONY: clean fclean test

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(LIB):
	$(MAKE) -C $(dir $(LIB))

$(ODIR)/%.o: %.c
	@mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@

test: $(NAME)
	./$(NAME)

clean:
	$(RM) -r $(ODIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(dir $(LIB)) fclean

re: fclean all
