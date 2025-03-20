NAME = minishell
LIB_PATH = lib
SRC_DIR = srcs
BUILD_DIR = obj

SRC_FILES = main.c 

HEADERS = srcs/minishell.h

INCLUDES = -I $(LIB_PATH) -I$(SRC_DIR)

LIBS = -L$(LIB_PATH) -lft

OBJS = $(SRC_FILES:%.c=$(BUILD_DIR)/%.o)

CC = cc 
CFLAGS =  -Wall -Wextra -Werror -g
RM = rm -rf
LDFLAGS = -lreadline
VALGRIND = valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all \
			--suppressions=readline.supp

all:			$(NAME)

$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) Makefile
				@mkdir -p $(BUILD_DIR)
				@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 

$(NAME):		$(OBJS)
				@$(MAKE) -C $(LIB_PATH)
				@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(LDFLAGS) -o $(NAME)

vg:				$(NAME)
				$(VALGRIND) ./$(NAME)

clean:
				@$(MAKE) -C $(LIB_PATH) clean
				@$(RM) $(BUILD_DIR)

fclean:			clean
				@$(MAKE) -C $(LIB_PATH) fclean
				@$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
