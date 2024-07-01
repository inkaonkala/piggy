#include "solong.h"
#include "mlx/mlx.h"

int	seed(void)
{
	static int	seed = 5;

	seed++;
	if (seed > 1000)
		seed = 3;
	return (seed);
}

void	exit_message(void)
{
	ft_printf("error\n");
	exit(1);
}

int	closing(t_game	*game)
{
	ft_printf("No time to play?\n B Y E!\n");
	exit (0);
	return (0);
}