LIBFT_DIR			=	libft
SRCS_DIR			=	srcs
HEADER_DIR			=	includes

SRCS_FLAT			=	flag_process/ft_add_hash.c flag_process/ft_add_padding.c flag_process/ft_add_precision.c flag_process/ft_add_sign.c \
						specifier_handling/handle_char.c specifier_handling/handle_decimal.c specifier_handling/handle_hexa.c specifier_handling/handle_percent.c \
						specifier_handling/handle_pointer.c specifier_handling/handle_string.c specifier_handling/handle_unsigned.c ft_printf.c ft_read_arg.c lookupmap.c

SRCS				=	$(addprefix srcs/, $(SRCS_FLAT)) 

OBJS				=	$(SRCS:.c=.o)

CC					=	gcc
RM					=	rm -f
FLAGS				=	-Wall -Wextra -Werror -I./$(HEADER_DIR)

NAME				=	libftprintf.a

%.o:				%.c $(HEADER_DIR)/ft_printf.h
					$(CC) $(FLAGS) -c $< -o $@

all:				$(NAME)

$(NAME):			$(OBJS)
					make -C $(LIBFT_DIR)
					cp $(LIBFT_DIR)/libft.a $(NAME)
					ar rcs $(NAME) $(OBJS)

clean:
					make clean -C $(LIBFT_DIR)	
					$(RM) $(OBJS)

fclean:				clean
					make fclean -C $(LIBFT_DIR)	
					$(RM) $(NAME)

re:					fclean $(NAME)

bonus:				all

.PHONY:				all clean fclean re bonus