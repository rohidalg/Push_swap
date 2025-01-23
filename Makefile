NAME = push_swap

MKL = make -s -C libft
MK = make -s
MKD = mkdir -p
RM = rm -rf
CC = gcc
CFLAGS = -Wall -Wextra -Werror  #-fsanitize=address -g3

HEADERS = push_swap.h \
			libft/libft.h \

INCLUDES = -I libft

SRCs = ft_check_number.c \
		ft_cheap_number.c \
		ft_algorithms.c \
		ft_push.c \
		ft_reverse_rotate.c \
		ft_rotate.c \
		ft_search.c \
		ft_swap.c \
		ft_utils.c \
		push_swap.c 


DIR_OBJs = OBJECTS

OBJs = $(addprefix $(DIR_OBJs)/,$(SRCs:%.c=%.o))

all: dir_lib $(NAME)

$(NAME): $(OBJs)
	$(CC) $(CFLAGS) $(OBJs) libft/libft.a -o $(NAME)

$(DIR_OBJs)/%.o: %.c | $(DIR_OBJs)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(DIR_OBJs):
	$(MKD) $(DIR_OBJs)

dir_lib: 
	$(MKL)

clean:
	$(MK) fclean -C libft
	$(RM) $(DIR_OBJs)

fclean: clean
	$(RM) $(NAME)

re: fclean all
