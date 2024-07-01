#include "solong.h"
#include "mlx/mlx.h"

void	start(char *map)
{
	t_game		game;
	int			len;
	int			heig;

	render_map(&game, map);
	game.mlx.mlx = mlx_init();
	len = game.map_lenght * 64;
	heig = game.map_hight * 64;
	game.mlx.window = mlx_new_window(game.mlx.mlx, len, heig, "oink oink");
	set_img(&game.mlx, &game.img);
	//wolf_it(&game);
	draw_img(&game.mlx, &game, &game.img);
	mlx_hook(game.mlx.window, 2, 1L << 0, &key_press, &game);
	mlx_hook(game.mlx.window, 17, 0, &closing, &game);
	mlx_loop(game.mlx.mlx);
	mlx_clear_window(game.mlx.mlx, game.mlx.window);
}
