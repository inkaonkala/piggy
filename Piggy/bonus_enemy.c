#include "solong.h"
#include "mlx/mlx.h"
#include "keycodes.h"

static void	set_wgrass(t_window *mlx, t_game *game, t_images *img)
{
	mlx_put_image_to_window(mlx->mlx, mlx->window, img->grass, game->enemy_x * 64, game->enemy_y * 64);
}

void	draw_wolf(t_window *mlx, t_game *game, t_images *img, int x, int y)
{
	
	static int i = 0;

	if (i % 2 == 0)
		mlx_put_image_to_window(mlx->mlx, mlx->window, img->wolf1, y * 64, x * 64);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->window, img->wolf2, y * 64, x * 64);
	i++;
}

void draw_wolf_again(t_window *mlx, t_game *game, t_images *img)
{
	draw_wolf(mlx, game, img, game->enemy_x, game->enemy_y);	
}

static void	game_over()
{
	ft_printf("You died\n");
	exit (1);
}

void	move_wolf(t_game *game, int x, int y, int keycode)
{
	if (keycode == KEY_D || keycode == KEY_A)
	{
		if (y > game->pig_x)
			y--;
		else if (y < game->pig_y)
			y++;
	}
	else
	{
		if (x > game->pig_y)
			x--;
		if (x < game->pig_x)
			x++;
	}
	if (game->map[x][y] == 'P')
		game_over();
	else if (game->map[x][y] == '0')
	{
		game->map[game->enemy_x][game->enemy_y] = '0';
		set_wgrass(&game->mlx, game, &game->img);
		game->enemy_x = x;
		game->enemy_y = y;
		game->map[x][y] = 'A';
		draw_wolf_again(&game->mlx, game, &game->img);
	}
}

void	wolf_it(t_game *game)
{
	int	i;

	i = 0;

	seed();
	while (i < 2)
	{
		while (1)
		{
			game->enemy_x = seed() % game->map_hight;
			game->enemy_y = seed() % game->map_lenght;
			if (game->map[game->enemy_x][game->enemy_y] == '0')
				break ;
		}
	i++;
	}
}