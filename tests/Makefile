CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar

ARFLAGS = -r -c -s

CP = cp

RM = rm

RMFLAGS = -r -f

TESTS_DIR = src

TESTS = $(TESTS_DIR)/dll.c $(TESTS_DIR)/command.c $(TESTS_DIR)/file.c \
		$(TESTS_DIR)/filepath.c $(TESTS_DIR)/stack.c $(TESTS_DIR)/parser.c \
		$(TESTS_DIR)/build_commands.c

TESTS_EXECS = $(TESTS:.c=.out)

ROOT_DIR = ..

INCLUDE_DIR = $(ROOT_DIR)/include

SRC_DIR = $(ROOT_DIR)/src

SRC = $(SRC_DIR)/dll.c $(SRC_DIR)/dll-helpers.c $(SRC_DIR)/command.c \
	  $(SRC_DIR)/file.c $(SRC_DIR)/filepath.c $(SRC_DIR)/stack.c \
	  $(SRC_DIR)/parser.c \
	  $(SRC_DIR)/parsing-table/build-parsing-table.c \
	  $(SRC_DIR)/parsing-table/parser-helpers1.c \
	  $(SRC_DIR)/parsing-table/parser-helpers2.c \
	  $(SRC_DIR)/build_commands.c $(SRC_DIR)/update_commands_files.c \

OBJ = $(SRC:.c=.o)

MINISHELL_NAME = minishell

MINISHELL_LIB = $(ROOT_DIR)/lib$(MINISHELL_NAME).a

CUT_DIR = cut

CUT_INCLUDE_DIR = $(CUT_DIR)/include

CUT_NAME = cut

CUT = $(CUT_DIR)/lib$(CUT_NAME).a

LIBFT_DIR = $(ROOT_DIR)/libft

LIBFT_INCLUDE_DIR = $(LIBFT_DIR)/include

LIBFT_NAME = ft

LIBFT = $(LIBFT_DIR)/lib$(LIBFT_NAME).a

IFLAGS = -I$(INCLUDE_DIR) -I$(CUT_INCLUDE_DIR) -I$(LIBFT_INCLUDE_DIR)

LDFLAGS = -L$(CUT_DIR) -L$(LIBFT_DIR) -L$(ROOT_DIR)

LDLIBS = -l$(CUT_NAME) -l$(LIBFT_NAME) -l$(MINISHELL_NAME)

all: $(TESTS_EXECS)

%.out: %.c $(MINISHELL_LIB) $(CUT) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $< $(IFLAGS) $(LDFLAGS) $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(IFLAGS)

$(MINISHELL_LIB): $(LIBFT) $(OBJ)
	$(CP) $(LIBFT_DIR)/$(LIBFT) $@
	$(AR) $(ARFLAGS) $@ $^

$(CUT):
	$(MAKE) -C $(CUT_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) clean -C $(ROOT_DIR)
	$(MAKE) clean -C $(CUT_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean:
	$(RM) $(RMFLAGS) $(TESTS_EXECS)
	$(MAKE) fclean -C $(ROOT_DIR)
	$(MAKE) fclean -C $(CUT_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all
