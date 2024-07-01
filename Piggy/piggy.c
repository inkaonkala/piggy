#include "solong.h"
#include "mlx/mlx.h"

void	draw_piggy(t_window *mlx, t_game *game, t_images *img, int x, int y)
{
	static int i = 0;

	if (game->pig_direc == 0)
	{
		if (i == 0)
		{
			mlx_put_image_to_window(mlx->mlx, mlx->window, img->pigR1, y * 64, x * 64);
			i = 1;
		}
		else
		{
			mlx_put_image_to_window(mlx->mlx, mlx->window, img->pigR2, y * 64, x * 64);
			i = 0;
		}
	}
	else if (game->pig_direc == 1)
	{
		if (i == 0)
		{
			mlx_put_image_to_window(mlx->mlx, mlx->window, img->pigL1, y * 64, x * 64);
			i = 1;
		}
		else
		{
			mlx_put_image_to_window(mlx->mlx, mlx->window, img->pigL2, y * 64, x * 64);
			i = 0;
		}
	}	
}