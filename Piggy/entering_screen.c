#include "solong.h"
#include "mlx/mlx.h"
#include "keycodes.h"

static int	close_opening(void *mlx, void *win)
{
	mlx_destroy_window(mlx, win);
	return (0);
}

static int	start_keys(int keycode)
{	

	void	*mlx;
	void	*win;

	if (keycode == KEY_ESC)
	{
		ft_printf("Bye bye\n");
		exit (0);
	}
	else if (keycode == KEY_ENTER)
	{
		close_opening(mlx, win);
	}
	return (0);
}

int	opening_screen()
{
	void	*mlx;
	void	*win;
	void	*img;

	int hi;
	int len;

	hi = 950;
	len = 500;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 960, 540, "Piggy");
	img = mlx_xpm_file_to_image(mlx, "piggy1.xpm", &hi, &len);
	mlx_put_image_to_window(mlx, win, img, 0, 0);

	mlx_hook(win, 2, 1L<<0, start_keys, mlx);
	mlx_hook(win, 17, 1L<<17, close_opening, mlx);
	mlx_loop(mlx);
	mlx_destroy_display(mlx);
	free(mlx);

	return (0);
	
}