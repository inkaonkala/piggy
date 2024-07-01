#include "solong.h"
#include "mlx/mlx.h"

void	draw_trees(t_window *mlx, t_game *game, t_images *img, int x, int y)
{
	
	static int i = 0;

	if (i % 3 == 0)
		mlx_put_image_to_window(mlx->mlx, mlx->window, img->manty, y * 64, x * 64);
	else if (i % 5 == 0)
		mlx_put_image_to_window(mlx->mlx, mlx->window, img->koivu2, y * 64, x * 64);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->window, img->koivu1, y * 64, x * 64);
	i++;
}

void	draw_shrooms(t_window *mlx, t_game *game, t_images *img, int x, int y)
{	
	static int i = 0;

	if (i % 3 == 2)
		mlx_put_image_to_window(mlx->mlx, mlx->window, img->shroom2, y * 64, x * 64);
	else if (i % 3 == 1)
		mlx_put_image_to_window(mlx->mlx, mlx->window, img->shroom3, y * 64, x * 64);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->window, img->shroom, y * 64, x * 64);
	i++;
}