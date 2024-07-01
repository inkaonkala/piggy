#include "solong.h"
#include "mlx/mlx.h"

static void	find_piggy(t_game *game, int i, int j, char c)
{
	if (c == 'P')
	{
		game->pig_x = i;
		game->pig_y = j;
	}
	game->pig_direc = 0;
}

void	checker(t_movabls *c, char chk)
{
	if(chk != '1' && chk != 'C' && chk != 'E' && chk != 'P' && chk != 'A')
	{
		ft_printf("Weird stuff on the field!\n");
		exit(1);
	}
	else if (chk == 'P')
	{
		if (c->player == 1)
		{
			ft_printf("I need only one player!\n");
			exit(1);
		}
		else
			c->player = 1;
	}
	else if (chk == 'C')
		c->collect = 1;
	else if (chk == 'E')
		c->exit = 1;
	
}

void	valid_map(t_game *game)
{
	int			i;
	int			j;
	t_movabls	check;

	check = (t_movabls){0, 0, 0};
	i = 0;
	while (i < game->map_hight)
	{
		j = 0;
		while (j < game->map_lenght)
		{
			if (i == 0 || j == 0 || i == game->map_hight - 1 || j == game->map_lenght - 1)
			{
				if (game->map[i][j] != '1')
				{
					ft_printf("No walls!\n");
					exit(1);
				}
			}
			else
			{
				if (game->map[i][j] != '0')
					checker(&check, game->map[i][j]);
				find_piggy(game, i, j, game->map[i][j]);
			}
			j++;
		}
		i++;
	}
	if (check.collect == 0 || check.exit == 0 || check.player == 0)
	{
		ft_printf("Missing stuff!\n");
		exit(1);
	}
	
}
