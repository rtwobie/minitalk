# config
CLIENT		:= client
SERVER		:= server
SRC_DIR		:= src
INC_DIR		:= inc
OBJ_DIR		:= obj
CC			:= cc

LIBFT		:= libft.a
LIBFT_DIR	:= libft

# flags
CFLAGS		:=
CFLAGS		+= -O2
CFLAGS		+= -Wall
CFLAGS		+= -Werror
CFLAGS		+= -Wextra

CPPFLAGS	:=
CPPFLAGS	+= $(addprefix -I, $(INC_DIR))
CPPFLAGS	+= $(addprefix -I, $(LIBFT_DIR))

ifeq ($(DEBUG), 1)
	CPPFLAGS	+= -ggdb3 -O0
endif

LDFLAGS		:=
LDFLAGS		+= -L$(LIBFT_DIR)

LDLIBS		+= -l$(patsubst lib%,%, $(basename $(LIBFT)))

# sources
vpath %.c src/cl
SRC_CLIENT	+= client.c

vpath %.c src/srv
SRC_SERVER	+= server.c

OBJ_CLIENT	:= $(SRC_CLIENT:.c=.o)
OBJ_CLIENT	:= $(addprefix $(OBJ_DIR)/, $(OBJ_CLIENT))

OBJ_SERVER	:= $(SRC_SERVER:.c=.o)
OBJ_SERVER	:= $(addprefix $(OBJ_DIR)/, $(OBJ_SERVER))

all: client server

$(LIBFT_DIR)/$(LIBFT):
	@make -C $(LIBFT_DIR)

client: $(LIBFT_DIR)/$(LIBFT) $(OBJ_CLIENT)
	$(CC) $(OBJ_CLIENT) $(LDFLAGS) $(LDLIBS) -o $(CLIENT)

server: $(LIBFT_DIR)/$(LIBFT) $(OBJ_SERVER)
	$(CC) $(OBJ_SERVER) $(LDFLAGS) $(LDLIBS) -o $(SERVER)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

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

.PHONY: all clean fclean re client server
