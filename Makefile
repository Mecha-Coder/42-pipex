#==============================================================
# DECLARATION
#==============================================================

NAME = pipex
CC = gcc
CFLAG = -Wall -Wextra -Werror
RM = rm -f

GNL_DIR = ./get_next_line
GNL_LIB = $(GNL_DIR)/get_next_line.a

#==============================================================
# FILES
#==============================================================

C_SRC = $(wildcard ./utils/*.c) \
	$(wildcard ./logic/*.c)

C_BONUS = pipex_bonus.c
C_MANDATORY = pipex.c


SRC = $(C_SRC:%.c=%.o)
MANDATORY = $(C_MANDATORY:%.c=%.o)
BONUS = $(C_BONUS:%.c=%.o)

#==============================================================
# BUILD COMMAND
#==============================================================

all: lib $(NAME) clean
#all : bonus

bonus: lib mkbonus clean

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

$(NAME): $(SRC) $(MANDATORY)
	$(CC) $(CFLAG) -o $@ $^ $(GNL_LIB)

mkbonus: $(SRC) $(BONUS) 
	$(CC) $(CFLAG) -o $(NAME) $^ $(GNL_LIB)

lib:
	make -C $(GNL_DIR) all

clean:
	$(RM) $(SRC) $(MANDATORY) $(BONUS) 

fclean: clean
	$(RM) $(NAME)
	make -C $(GNL_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus