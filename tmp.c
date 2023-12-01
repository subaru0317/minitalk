#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])

{
	int x;
	x = ft_atoi("abc123");
	printf("%d\n", x);
	x = atoi("abc123");
	printf("%d\n", x);
	x = ft_atoi("123abc");
	printf("%d\n", x);
	x = atoi("123abc");
	printf("%d\n", x);
}