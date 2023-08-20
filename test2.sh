gcc client.c -o client libft/libft.a
time ./client $1 `python3 -c "print('b'*$2)"`
