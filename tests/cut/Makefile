LIB = libcut.a

AR = ar

ARFLAGS = -r -c -s

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm

RMFLAGS = -r -f

INCLUDE_DIR = include

INCLUDE = $(INCLUDE_DIR)/cut.h

SRC_DIR = src

SRC = $(SRC_DIR)/assert.c $(SRC_DIR)/compare.c $(SRC_DIR)/expect.c \
	  $(SRC_DIR)/output.c $(SRC_DIR)/unit-test.c

OBJ = $(SRC:.c=.o)

IFLAGS = -I$(INCLUDE_DIR)

all: $(LIB)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -o $@ -c $< $(IFLAGS)

$(LIB): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

clean:
	$(RM) $(RMFLAGS) $(OBJ)

fclean: clean
	$(RM) $(RMFLAGS) $(LIB)

re: fclean all
