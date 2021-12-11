make > /dev/null
gcc -fsanitize=address -g -L. -I./includes test.c -lftprintf
make fclean > /dev/null