
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
	{
		//ft_printf("test ft: %d, %s\n", turn, av[1]);
		ft_printf( "%-5c ", 42);
		ft_printf("%%\n");
		ft_printf("%%%%%d\n", -120);
		ft_printf("size + espace + zero + prec:%0 5.3d ", -879650);
		ft_printf("max long :  %ld", LONG_MAX);
		ft_printf("min long :  %ld", LONG_MIN);
		ft_printf("space + prec + hash:% #.0f\n", -0.000);
		ft_printf("Plus + prec / grande:%+.5f\n", -0.000);
		ft_printf("size + 0 + prec:%05.3f\n", -45.123456789);
		ft_printf("size + 0 + prec + hash:%0#5.0f\n", -45.123456789);
		ft_printf("size + minus + prec:%-5.3f\n", 45.123456789);
		ft_printf("%X %12o %5s %x %d qdaze %c", -123, -432, "okqsd", 5643, 123654, 'S');
		ft_printf("%X %o %s %x %d qdaze %c \n %c", 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W');
		ft_printf("%X %o %s %x %d qdaze %c \n %c", 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W');
		ft_printf("%X %o %s %5x %d qdaze %5c \n %c %X %o %s %x %d qdaze %c \n %c", 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W', 1233, 123432, "okdsq qsqsd", 6542, -123654, 'U', 'W');
	}
}
