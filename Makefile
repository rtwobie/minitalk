# config
CLIENT		:= client
SERVER		:= server
CC			:= cc
SRC_DIR		:= src
INC_DIR		:= inc
OBJ_DIR		:= OBJ

LIBFT		:= libft.a
LIBFT_DIR	:= libft

# flags
CFLAGS		:=
CFLAGS		+= -Wall
CFLAGS		+= -Werror
CFLAGS		+= -Wextra

CPPFLAGS	:=
CPPFLAGS	+= -g

LDFLAGS		:=
LDFLAGS		+= -L$(LIBFT_DIR)

LDLIBS		+= -l$(basename $(LIBFT))

# sources
SRC			:=

vpath %.c src
SRC			:= main.c

OBJ			:= $(SRC:.c=.o)
OBJ			:= $(addprefix $(OBJ_DIR)/, $(OBJ))

all: $(CLIENT) $(SERVER)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(CLIENT):

$(SERVER):

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(CLIENT)
	rm -f $(SERVER)
	make -C $(LIBFT_DIR) fclean

re:
	@make fclean
	@make all

.PHONY: all clean fclean re
