make > /dev/null
gcc -g -L. -I./includes test.c -lftprintf
make fclean > /dev/null