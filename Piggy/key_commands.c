#include "solong.h"
#include "mlx/mlx.h"
#include "keycodes.h"

void	set_grass(t_window *mlx, t_game *game, t_images *img)
{
	mlx_put_image_to_window(mlx->mlx, mlx->window, img->grass, game->pig_y * 64, game->pig_x * 64);
}

static void print_steps(t_game *game)
{
	ft_printf("Steps taken: %d\n", game->step_count);
}

static int	can_exit(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_hight)
	{
		j = 0;
		while (j < game->map_lenght)
		{
			if (game->map[i][j] == 'C')
				return (0);
			j++;

		}
		i++;
	}
	return (1);
}

static void	player_location(t_game *game, int x, int y)
{
	if (x >= 0 && y >= 0 && x < game->map_hight && y < game->map_lenght)
	{
		if (game->map[x][y] == 'E')
		{
			if (can_exit(game))
			{
				print_steps(game);
				ft_printf("Piggy escaped to speace!\n");
				exit (0);
			}
		}
		else if (game->map[x][y] == 'A')
		{
			ft_printf("You died\n");
			exit (0);
		}
		else if (game->map[x][y] != '1')
		{
			game->map[game->pig_x][game->pig_y] = '0';
			set_grass(&game->mlx, game, &game->img);
			game->pig_x = x;
			game->pig_y = y;
			game->map[x][y] = 'P';
			draw_again(&game->mlx, game, &game->img);
			game->step_count++;
			print_steps(game);
		}
	}
}

int	key_press(int keycode, t_game *game)
{
	move_wolf(game, game->enemy_x, game->enemy_y, keycode);
	if (keycode == KEY_ESC)
	{
		ft_printf("bye bye\n");
		exit (0);
	}
	if (keycode == KEY_W)
		player_location(game, game->pig_x - 1, game->pig_y);
	
	else if (keycode == KEY_S)
		player_location(game, game->pig_x + 1, game->pig_y);
	
	else if (keycode == KEY_D)
	{
		game->pig_direc = 0;
		player_location(game, game->pig_x, game->pig_y + 1);
	}
	
	else if (keycode == KEY_A)
	{
		game->pig_direc = 1;
		player_location(game, game->pig_x, game->pig_y - 1);
	}
	else if (keycode == '-')
		draw_img(&game->mlx, game, &game->img);
	return (0);
}
