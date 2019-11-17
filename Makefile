# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nschat <nschat@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/30 12:13:23 by nschat        #+#    #+#                  #
#    Updated: 2019/11/17 18:35:20 by nschat        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc
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

NAME = run_tests

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

vpath %.c tests

.PHONY: clean fclean test

all: $(NAME)

$(NAME): $(LIB) | $(OBJ)
	@echo "$(TIME) $(CPLUS) $(CGREEN)Linking objects into $@...$(CDEF)"
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $|

$(LIB):
	@echo "$(TIME) $(CNORM) $(CCYAN)Running make in $(dir $(LIB))...$(CDEF)"
	@$(MAKE) "DEBUG=${DEBUG}" -C $(dir $(LIB))

bonus: $(LIB) | $(OBJ) $(BOBJ)
	@echo "$(TIME) $(CNORM) $(CCYAN)Running make bonus in $(dir $(LIB))...$(CDEF)"
	@$(MAKE) bonus "DEBUG=${DEBUG}" -C $(dir $(LIB))
	@echo "$(TIME) $(CPLUS) $(CGREEN)Linking bonus objects into $(NAME)...$(CDEF)"
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $|

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
