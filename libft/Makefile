NAME = libft.a

AR = ar

ARFLAGS = -r -c -s

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDE_DIR = include

SRC_DIR = src

INCLUDE = $(INCLUDE_DIR)/libft.h $(INCLUDE_DIR)/conv.h \
		  $(INCLUDE_DIR)/typeutils.h $(INCLUDE_DIR)/get_next_line.h

SRC = $(SRC_DIR)/ft_isalpha.c $(SRC_DIR)/ft_isdigit.c $(SRC_DIR)/ft_isalnum.c \
	  $(SRC_DIR)/ft_isascii.c $(SRC_DIR)/ft_isprint.c $(SRC_DIR)/ft_strlen.c \
	  $(SRC_DIR)/ft_memset.c $(SRC_DIR)/ft_bzero.c $(SRC_DIR)/ft_memcpy.c \
	  $(SRC_DIR)/ft_memmove.c $(SRC_DIR)/ft_strlcpy.c $(SRC_DIR)/ft_strlcat.c \
	  $(SRC_DIR)/ft_toupper.c $(SRC_DIR)/ft_tolower.c $(SRC_DIR)/ft_strchr.c \
	  $(SRC_DIR)/ft_strrchr.c $(SRC_DIR)/ft_strncmp.c $(SRC_DIR)/ft_memchr.c \
	  $(SRC_DIR)/ft_memcmp.c $(SRC_DIR)/ft_strnstr.c $(SRC_DIR)/ft_atoi.c \
	  $(SRC_DIR)/ft_calloc.c $(SRC_DIR)/ft_strdup.c $(SRC_DIR)/ft_substr.c \
	  $(SRC_DIR)/ft_strjoin.c $(SRC_DIR)/ft_strtrim.c $(SRC_DIR)/ft_split.c \
	  $(SRC_DIR)/ft_itoa.c $(SRC_DIR)/ft_strmapi.c $(SRC_DIR)/ft_striteri.c \
	  $(SRC_DIR)/ft_putchar_fd.c $(SRC_DIR)/ft_putstr_fd.c \
	  $(SRC_DIR)/ft_putendl_fd.c $(SRC_DIR)/ft_putnbr_fd.c \
	  $(SRC_DIR)/ft_free_arr.c $(SRC_DIR)/ft_close.c \
	  $(SRC_DIR)/ft_printf/conv.c $(SRC_DIR)/ft_printf/ft_itoa_base.c \
	  $(SRC_DIR)/ft_printf/ft_pitoa_base.c $(SRC_DIR)/ft_printf/ft_printf.c \
	  $(SRC_DIR)/ft_printf/ft_dprintf.c $(SRC_DIR)/ft_printf/libft-string.c \
	  $(SRC_DIR)/ft_printf/ft_uitoa_base.c $(SRC_DIR)/ft_printf/print_conv.c \
	  $(SRC_DIR)/ft_printf/typeutils.c $(SRC_DIR)/get_next_line/get_next_line.c \
	  $(SRC_DIR)/get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

BONUS_SUFFIX = _bonus

BONUS_SRC = $(SRC_DIR)/ft_lstnew$(BONUS_SUFFIX).c \
			$(SRC_DIR)/ft_lstadd_front$(BONUS_SUFFIX).c \
			$(SRC_DIR)/ft_lstsize$(BONUS_SUFFIX).c \
			$(SRC_DIR)/ft_lstlast$(BONUS_SUFFIX).c \
			$(SRC_DIR)/ft_lstadd_back$(BONUS_SUFFIX).c \
			$(SRC_DIR)/ft_lstdelone$(BONUS_SUFFIX).c \
			$(SRC_DIR)/ft_lstclear$(BONUS_SUFFIX).c \
			$(SRC_DIR)/ft_lstiter$(BONUS_SUFFIX).c \
			$(SRC_DIR)/ft_lstmap$(BONUS_SUFFIX).c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDE_DIR)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

clean:
	rm -rf $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

bonus: $(OBJ) $(BONUS_OBJ)
	$(AR) $(ARFLAGS) $(NAME) $^
