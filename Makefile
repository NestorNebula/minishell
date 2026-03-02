NAME = minishell 

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm

RMFLAGS = -r -f

ROOT_DIR = .

INCLUDE_DIR = $(ROOT_DIR)/include

SRC_DIR = $(ROOT_DIR)/src

SRC = $(SRC_DIR)/build_commands.c $(SRC_DIR)/builtins.c $(SRC_DIR)/command.c \
	  $(SRC_DIR)/dll.c $(SRC_DIR)/dll-helpers.c $(SRC_DIR)/env.c \
	  $(SRC_DIR)/env_convert.c $(SRC_DIR)/env_free.c $(SRC_DIR)/env_init.c \
	  $(SRC_DIR)/expand_args.c $(SRC_DIR)/expansion.c \
	  $(SRC_DIR)/expansion_utils.c $(SRC_DIR)/file.c $(SRC_DIR)/filepath.c \
	  $(SRC_DIR)/heredoc.c $(SRC_DIR)/heredoc-utils.c $(SRC_DIR)/minishell.c \
	  $(SRC_DIR)/parse.c $(SRC_DIR)/parser.c $(SRC_DIR)/prompt.c \
	  $(SRC_DIR)/shell.c $(SRC_DIR)/sig_handlers.c $(SRC_DIR)/signal.c \
	  $(SRC_DIR)/stack.c $(SRC_DIR)/token.c $(SRC_DIR)/tokenizer.c \
	  $(SRC_DIR)/tokenizer-helpers.c $(SRC_DIR)/update_commands_files.c \
	  $(SRC_DIR)/builtins/cd.c $(SRC_DIR)/builtins/echo.c \
	  $(SRC_DIR)/builtins/env.c $(SRC_DIR)/builtins/exit.c \
	  $(SRC_DIR)/builtins/export.c $(SRC_DIR)/builtins/pwd.c \
	  $(SRC_DIR)/builtins/unset.c $(SRC_DIR)/exec/child.c \
	  $(SRC_DIR)/exec/end-exec.c $(SRC_DIR)/exec/exec.c \
	  $(SRC_DIR)/exec/exec-command.c $(SRC_DIR)/exec/exec-line.c \
	  $(SRC_DIR)/exec/handle-command.c $(SRC_DIR)/exec/parent.c \
	  $(SRC_DIR)/exec/post-exec.c $(SRC_DIR)/exec/prepare-command.c \
	  $(SRC_DIR)/exec/prepare-files.c $(SRC_DIR)/exec/wait.c \
	  $(SRC_DIR)/parsing-table/build-parsing-table.c \
	  $(SRC_DIR)/parsing-table/parser-helpers1.c \
	  $(SRC_DIR)/parsing-table/parser-helpers2.c

OBJ = $(SRC:.c=.o)

LIBFT_DIR = $(ROOT_DIR)/libft

LIBFT_INCLUDE_DIR = $(LIBFT_DIR)/include

LIBFT_NAME = ft

LIBFT = $(LIBFT_DIR)/lib$(LIBFT_NAME).a

IFLAGS = -I$(INCLUDE_DIR) -I$(LIBFT_INCLUDE_DIR)

LDFLAGS = -L$(LIBFT_DIR)

LDLIBS = -l$(LIBFT_NAME) -lreadline

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(IFLAGS)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(RMFLAGS) $(OBJ)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean:
	$(RM) $(RMFLAGS) $(OBJ)
	$(RM) $(RMFLAGS) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all
