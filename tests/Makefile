CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm

RMFLAGS = -r -f

TESTS_DIR = src

TESTS = $(TESTS_DIR)/dll.c $(TESTS_DIR)/command.c $(TESTS_DIR)/fd.c

TESTS_EXECS = $(TESTS:.c=.out)

ROOT_DIR = ..

INCLUDE_DIR = $(ROOT_DIR)/include

SRC_DIR = $(ROOT_DIR)/src

SRC = $(SRC_DIR)/dll.c $(SRC_DIR)/command.c $(SRC_DIR)/fd.c

OBJ = $(SRC:.c=.o)

CUT_DIR = cut

CUT_INCLUDE_DIR = $(CUT_DIR)/include

CUT_NAME = cut

CUT = $(CUT_DIR)/lib$(CUT_NAME).a

LIBFT_DIR = $(ROOT_DIR)/libft

LIBFT_INCLUDE_DIR = $(LIBFT_DIR)/include

LIBFT_NAME = ft

LIBFT = $(LIBFT_DIR)/lib$(LIBFT_NAME).a

IFLAGS = -I$(INCLUDE_DIR) -I$(CUT_INCLUDE_DIR) -I$(LIBFT_INCLUDE_DIR)

LDFLAGS = -L$(CUT_DIR) -L$(LIBFT_DIR)

LDLIBS = -l$(CUT_NAME) -l$(LIBFT_NAME)

all: $(TESTS_EXECS)

%.out: %.c $(SRC) $(CUT) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $< $(SRC) $(IFLAGS) $(LDFLAGS) $(LDLIBS)

%.o: %.c
	$(MAKE) $@ -C $(ROOT_DIR)

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
