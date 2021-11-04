LIBFT				=	libft

HEADER				=	includes

SRCS_DIR			=	srcs

SRCS_NAME			=	ft_printf.c \
							lookupmap.c \
							parse_arg.c \
							add_padding.c \
							specifier_handling/handle_decimal.c \
							specifier_handling/handle_string.c \
							specifier_handling/handle_char.c \
							specifier_handling/handle_hexa.c \
							specifier_handling/handle_pointer.c

SRCS				=	$(addprefix $(SRCS_DIR)/, $(SRCS_NAME))

OBJS				=	$(SRCS:.c=.o)

CC					=	gcc
RM					=	rm -f
FLAGS				=	-Wall -Wextra -Werror -I./$(HEADER)

# -I./$(LIBFT)

NAME				=	libftprintf.a

%.o:				%.c
					$(CC) $(FLAGS) -c $< -o $@

all:				$(NAME)

$(NAME):			$(OBJS) $(HEADER)/ft_printf.h
					make -C $(LIBFT)
					cp $(LIBFT)/libft.a $(NAME)
					ar rcs $(NAME) $(OBJS)

clean:
					make clean -C $(LIBFT)	
					$(RM) $(OBJS)

fclean:				clean
					make fclean -C $(LIBFT)	
					$(RM) $(NAME)

re:					fclean $(NAME)

.PHONY:				all clean fclean re bonus so