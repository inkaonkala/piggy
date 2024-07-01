#include "solong.h"
#include "mlx/mlx.h"

int	main(int arc, char **arv)
{
	t_game	game;
	
	if(arc < 2)
	{
		ft_printf("Something's missing!\n");
		exit(1);
	}
	else if (arc == 2)
	{
		//if (opening_screen() > 1)
			start(arv[1]);
	}
	else
	{
		ft_printf("Too many things!");
		exit(1);
	}
	return (0);
}

//https://github.com/rbiodies/so_long/tree/main