# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nschat <nschat@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/30 12:13:23 by nschat        #+#    #+#                  #
#    Updated: 2019/11/30 20:26:39 by nschat        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I libft
LDFLAGS = -L libft -lcriterion -lft

SRC = test_mem.c test_misc.c test_str.c test_part2.c test_list.c

ODIR = obj
OBJ = $(addprefix $(ODIR)/,$(SRC:.c=.o))

LIB = libft/libft.a

NAME = run_tests

define ASCII
 __                   __             ___        __         ___  __
/\\ \\__               /\\ \\__         /\\_ \\    __/\\ \\      /'___\\/\\ \\__
\\ \\ ,_\\    __    ____\\ \\ ,_\\        \\//\\ \\  /\\_\\ \\ \\____/\\ \\__/\\ \\ ,_\\
 \\ \\ \\/  /'__`\\ /',__\\\\ \\ \\/          \\ \\ \\ \\/\\ \\ \\ '__`\\ \\ ,__\\\\ \\ \\/
  \\ \\ \\_/\\  __//\\__, `\\\\ \\ \\_          \\_\\ \\_\\ \\ \\ \\ \\L\\ \\ \\ \\_/ \\ \\ \\_
   \\ \\__\\ \\____\\/\\____/ \\ \\__\\         /\\____\\\\ \\_\\ \\_,__/\\ \\_\\   \\ \\__\\
    \\/__/\\/____/\\/___/   \\/__/  _______\\/____/ \\/_/\\/___/  \\/_/    \\/__/
                               /\\______\\
                               \\/______/
endef

CRED = \x1b[31m
CGREEN = \x1b[32m
CYELLOW = \x1b[33m
CBLUE = \x1b[34m
CCYAN = \x1b[36m
CDEFAULT = \x1b[39m
CDEF = $(CDEFAULT)

CMINUS = $(CRED)[-]$(CDEF)
CPLUS = $(CGREEN)[+]$(CDEF)
CNORM = $(CYELLOW)[~]$(CDEF)

TIME = $(CCYAN)[$$(date +"%H:%M:%S")]$(CDEF)

vpath %.c tests

.PHONY: clean fclean test

all: ascii $(NAME)

export ASCII
ascii:
	@echo "\n$(CYELLOW)$$ASCII$(CDEF)\n"

$(NAME): $(LIB) | $(OBJ)
	@echo "$(TIME) $(CPLUS) $(CGREEN)Linking objects into $@...$(CDEF)"
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $|

$(LIB):
	@echo "$(TIME) $(CNORM) $(CCYAN)Running make in $(dir $(LIB))...$(CDEF)"
	@$(MAKE) -C $(dir $(LIB))

$(ODIR)/%.o: %.c
	@echo "$(TIME) $(CPLUS) $(CBLUE)Compiling $< to $@...$(CDEF)"
	@mkdir -p $(ODIR)
	@$(CC) $(CFLAGS) -c $< -o $@

test: $(NAME)
	@echo "$(TIME) $(CNORM) $(CCYAN)Running $(NAME)...$(CDEF)"
	@./$(NAME) --verbose

clean:
	@echo "$(TIME) $(CMINUS) $(CRED)Cleaning object files...$(CDEF)"
	@$(RM) -r $(ODIR)

fclean: clean
	@echo "$(TIME) $(CMINUS) $(CRED)Cleaning $(NAME)...$(CDEF)"
	@$(RM) $(NAME)
	@echo "$(TIME) $(CNORM) $(CCYAN)Running make fclean in $(dir $(LIB))...$(CDEF)"
	@$(MAKE) fclean -C $(dir $(LIB))

re: fclean all
