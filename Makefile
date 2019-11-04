# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nschat <nschat@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/30 12:13:23 by nschat        #+#    #+#                  #
#    Updated: 2019/11/04 13:34:44 by nschat        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Wextra -Werror -I include -I libft/include \
		 -isystem ${BREW}/include
LDFLAGS = -L ${BREW}/lib -lcriterion
ARGS = -g -fprofile-instr-generate -fcoverage-mapping

SRC = test_mem.c test_misc.c test_str.c test_part2.c test_bonus.c

ODIR = obj
OBJ = $(addprefix $(ODIR)/,$(SRC:.c=.o))

LIB = libft/libft.a

NAME = test_libft

vpath %.c src

.PHONY: clean fclean test

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(ARGS) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(LIB):
	$(MAKE) "ARGS=$(ARGS)" -C $(dir $(LIB))
	$(MAKE) bonus "ARGS=$(ARGS)" -C $(dir $(LIB))

$(ODIR)/%.o: %.c
	@mkdir -p $(ODIR)
	$(CC) $(ARGS) $(CFLAGS) -c $< -o $@

test: $(NAME)
	./$(NAME)

clean:
	$(RM) -r $(ODIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(dir $(LIB)) fclean

re: fclean all
