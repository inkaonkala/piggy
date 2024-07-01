#include "solong.h"
#include "mlx/mlx.h"

static void	set_fgrass(t_window *mlx, t_game *game, t_images *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_hight)
	{
		j = 0;
		while (j < game->map_lenght)
		{
			mlx_put_image_to_window(mlx->mlx, mlx->window, img->grass, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void draw_again(t_window *mlx, t_game *game, t_images *img)
{
	draw_piggy(mlx, game, img, game->pig_x, game->pig_y);
	draw_wolf_again(mlx, game, img);
}

void	draw_img(t_window *mlx, t_game *game, t_images *img)
{
	int	i;
	int	j;

	set_fgrass(mlx, game, img);
	i = 0;
	while (i < game->map_hight)
	{
		j = 0;
		while (j < game->map_lenght)
		{
			if (game->map[i][j] == '1')
				draw_trees(mlx, game, img, i, j);
			else if (game->map[i][j] == 'P')
				draw_piggy(mlx, game, img, i, j);
			else if (game->map[i][j] == 'C')
				draw_shrooms(mlx, game, img, i, j);
			else if (game->map[i][j] == 'A')
				draw_wolf(mlx, game, img, i, j);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->window, img->ending, j * 64, i * 64);
			j++;
		}
		i++;
	}	
}

static void	*save_img(t_window *mlx, char *pic)
{
	void	*result;
	int		y;
	int		x;

	y = 0;
	x = 0;
	result = mlx_xpm_file_to_image(mlx->mlx, pic, &x, &y);
	if (x == 0 || y == 0)
	{
		ft_printf("Missing an image\n");
		exit(1);
	}
	return (result);
}

void	set_img(t_window *mlx, t_images *img)
{
	img->pigL1 = save_img(mlx, "pic/piggyL1.xpm");
	img->pigL2 = save_img(mlx, "pic/piggyL2.xpm");
	img->pigR1 = save_img(mlx, "pic/piggyR1.xpm");
	img->pigR2 = save_img(mlx, "pic/piggyR2.xpm");
	img->shroom = save_img(mlx, "pic/shroom.xpm");
	img->shroom2 = save_img(mlx, "pic/shroomy.xpm");
	img->shroom3 = save_img(mlx, "pic/shroomr.xpm");
	img->grass = save_img(mlx, "pic/grass.xpm");
	img->koivu1 = save_img(mlx, "pic/koivu.xpm");
	img->koivu2 = save_img(mlx, "pic/koivu2.xpm");
	img->manty = save_img(mlx, "pic/manty.xpm");
	img->ending = save_img(mlx, "pic/exit.xpm");
	img->wolf1 = save_img(mlx, "pic/wolf1.xpm");
	img->wolf2 = save_img(mlx, "pic/wolf2.xpm");
}
