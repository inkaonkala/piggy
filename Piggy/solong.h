#ifndef SOLONG_H
# define SOLONG_H

# ifndef MAXFD
# define MAXFD 1000
# endif

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h> // for strcmp
# include "mlx/mlx.h"
# include "libft.h"
# include "keycodes.h"

typedef struct s_window
{
	void	*mlx;
	void	*window;
} t_window;

typedef struct s_images
{
	void	*pigL1;
	void	*pigL2;
	void	*pigR1;
	void	*pigR2;
	void	*koivu1;
	void	*koivu2;
	void	*manty;
	void	*shroom;
	void	*shroom2;
	void	*shroom3;
	void	*ending;
	void	*enemy;
	void	*grass;
	void	*wolf1;
	void	*wolf2;	
}	t_images;


typedef struct	s_game
{
	t_window	mlx;
	t_window	win;
	t_images	img;

	int		map_lenght;
	int		map_hight;
	char 	**map;

	int		pig_x;
	int		pig_y;
	int		pig_direc; 

	int		shroom_count;
	int		step_count;

	int		enemy_x;
	int		enemy_y;
	int		enemy_count;

	int		gameover;
}	t_game;

typedef struct	s_movabls
{
	int	player;
	int	exit;
	int collect;
}	t_movabls;


int main(int arc, char **arv);

int		opening_screen();

void	start(char *map);

void	valid_map(t_game *game);
void	checker(t_movabls *c, char chk);

void	render_map(t_game *game, char *file);

void	set_img(t_window *mlx, t_images *img);
void	draw_img(t_window *mlx,t_game *game, t_images *img);
void	draw_again(t_window *mlx, t_game *game, t_images *img);

int		key_press(int keycode, t_game *game);
void	set_grass(t_window *mlx, t_game *game, t_images *img);

void	draw_piggy(t_window *mlx, t_game *game, t_images *img, int x, int y);

void	draw_trees(t_window *mlx, t_game *game, t_images *img, int x, int y);
void	draw_shrooms(t_window *mlx, t_game *game, t_images *img, int x, int y);

void	wolf_it(t_game *game);
void	draw_wolf(t_window *mlx, t_game *game, t_images *img, int x, int y);
void	move_wolf(t_game *game, int x, int y, int keycode);
void	draw_wolf_again(t_window *mlx, t_game *game, t_images *img);

void	exit_message(void);
int		closing(t_game	*game);
int		seed(void);

#endif
