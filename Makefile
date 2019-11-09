# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nschat <nschat@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/30 12:13:23 by nschat        #+#    #+#                  #
#    Updated: 2019/11/09 21:24:03 by nschat        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Wextra -Werror -I libft
ifeq (${DEBUG},true)
	CFLAGS := -g -fprofile-instr-generate -fcoverage-mapping $(CFLAGS)
endif
LDFLAGS = -L libft -lcriterion -lft

SRC = test_mem.c test_misc.c test_str.c test_part2.c
BSRC = test_bonus.c

ODIR = obj
OBJ = $(addprefix $(ODIR)/,$(SRC:.c=.o))
BOBJ = $(addprefix $(ODIR)/,$(BSRC:.c=.o))

LIB = libft/libft.a

NAME = test_libft

CRED=\x1b[31m
CGREEN=\x1b[32m
CYELLOW=\x1b[33m
CBLUE=\x1b[34m
CCYAN=\x1b[36m
CDEFAULT=\x1b[39m
CDEF=$(CDEFAULT)

CMINUS=$(CRED)[-]$(CDEF)
CPLUS=$(CGREEN)[+]$(CDEF)
CNORM=$(CYELLOW)[~]$(CDEF)

TIME=$(CCYAN)[$$(date +"%H:%M:%S")]$(CDEF)

vpath %.c src

.PHONY: clean fclean test

all: $(NAME)

$(NAME): $(LIB) | $(OBJ)
	@printf "$(TIME) $(CPLUS) $(CGREEN)"
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $|
	@printf "$(CDEF)"

$(LIB):
	@printf "$(TIME) $(CNORM) $(CCYAN)"
	$(MAKE) "DEBUG=${DEBUG}" -C $(dir $(LIB))
	@printf "$(CDEF)"

bonus: $(LIB) | $(OBJ) $(BOBJ)
	@printf "$(TIME) $(CNORM) $(CCYAN)"
	$(MAKE) bonus "DEBUG=${DEBUG}" -C $(dir $(LIB))
	@printf "$(CDEF)"
	@printf "$(TIME) $(CPLUS) $(CGREEN)"
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $|
	@printf "$(CDEF)"

$(ODIR)/%.o: %.c
	@printf "$(TIME) $(CPLUS) $(CBLUE)"
	@mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(CDEF)"

test: $(NAME)
	@printf "$(TIME) $(CNORM) $(CCYAN)"
	./$(NAME) --verbose
	@printf "$(CDEF)"

clean:
	@printf "$(TIME) $(CMINUS) $(CRED)"
	$(RM) -r $(ODIR)
	@printf "$(CDEF)"

fclean: clean
	@printf "$(TIME) $(CMINUS) $(CRED)"
	$(RM) $(NAME)
	@printf "$(CDEF)"
	@printf "$(TIME) $(CNORM) $(CCYAN)"
	$(MAKE) -C $(dir $(LIB)) fclean
	@printf "$(CDEF)"

re: fclean all
