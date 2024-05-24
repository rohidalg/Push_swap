NAME = push_swap

MKB = make bonus -s
MK = make -s
MKD = mkdir -p
RM = rm -rf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

HEADERS = push_swap.h \
			libft/libft.h \

INCLUDES = libft/bonus_libft.a

SRCs = ft_check_number.c \
		push_swap.c \
		ft_operation.c \


DIR_OBJs = OBJECTS

OBJs = $(addprefix $(DIR_OBJs)/,$(SRCs:%.c=%.o))

all: make_lib $(NAME)

$(NAME): $(OBJs)
	ar rcs $(NAME) $(OBJs)

$(DIR_OBJs)/%.o: %.c | $(DIR_OBJs)
	$(CC) $(CFLAGS) -c $< -o $@

$(DIR_OBJs):
	$(MKD) $(DIR_OBJs)

make_lib :
		$(MKB) -C libft

clean:
	$(MK) fclean -C libft
	$(RM) $(DIR_OBJs)

fclean: clean
	$(RM) $(NAME)

re: fclean all
