
#include <stdlib.h>
#include <stdio.h>
#include "../inc/ft_printf.h"

int		main(int ac, char **av)
{
	if (!ac)
		return (0);
	int turn;
	turn = atoi(av[1]);
	while (--turn)
		printf("test ft: %d, %s\n", turn, av[1]);
}
