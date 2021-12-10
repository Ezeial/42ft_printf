LIBFT_DIR			=	libft
SRCS_DIR			=	srcs
HEADER_DIR				=	includes

SRCS				=	$(wildcard $(SRCS_DIR)/*.c) \
							# $(wildcard $(SRCS_DIR)/*/*.c) \
							# $(wildcard $(SRCS_DIR)/*/*/*.c)

OBJS				=	$(SRCS:.c=.o)

CC					=	gcc
RM					=	rm -f
FLAGS				=	-g -Wall -Wextra -Werror -I./$(HEADER_DIR)

NAME				=	libftprintf.a

%.o:				%.c $(HEADER_DIR)/libftprintf.h
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

.PHONY:				all clean fclean re bonus so