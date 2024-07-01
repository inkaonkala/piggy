#include "solong.h"
#include "mlx/mlx.h"
/*
#include "solong.h"
#include "mlx/mlx.h"

static int check_map(t_game *game, char *filename) {
    int fd;
    char *line;
    int width;
    int height;

    fd = open(filename, O_DIRECTORY);
    if (fd > 0)
        exit_message();
    fd = open(filename, O_RDONLY);
    // STRCMP!!!
    if (fd < 0 || strcmp(".ber", &filename[ft_strlen(filename) - 4])) {
        ft_printf("chkmap1\n");
        exit_message();
    }
    line = get_next_line(fd);
    if (!line)
        exit_message();
    width = ft_strlen(line) - 1; // to ignore newline
    height = 0;
    while (line) {
        ft_printf("Line: %s", line); // Debug print
        if (width != ft_strlen(line) - 1) 
		{ // same if no newline, take -1 off
            ft_printf("chkmap2\n");
            exit_message();
        }
        free(line);
        line = get_next_line(fd);
        height++;
    }
    close(fd);
    game->map_hight = height;
    ft_printf("Final width: %d\n", width); // Debug print
    ft_printf("Final height: %d\n", height); // Debug print
    return (width);
}

void render_map(t_game *game, char *file) 
{
    int fd;
    char *line;
    int i;

    game->map_lenght = check_map(game, file);
	ft_printf("In render_map: game->map_lenght=%d\n", game->map_lenght);
    fd = open(file, O_RDONLY);
    if (fd < 0) 
	{
        ft_printf("Error in render\n");
        exit_message();
    }
    game->map = (char **)malloc(sizeof(char *) * game->map_hight);
    line = get_next_line(fd);
    i = 0;
    while (line) 
	{
        game->map[i] = line;
        line = get_next_line(fd);
        i++;
    }
    // Debug print
    for (int i = 0; i < game->map_hight; i++) 
	{
        ft_printf("%s", game->map[i]);
    }
	ft_printf("In render_map: game->map_lenght=%d\n", game->map_lenght);
    free(line);
    close(fd);
    game->step_count = 0;
    valid_map(game);
}
*/




static int	check_map(t_game *game, char *filename)
{
	int		fd;
	char	*line;
	int		width;
	int		height;

	fd = open(filename, O_DIRECTORY);
	if (fd > 0)
		exit_message();
	fd = open(filename, O_RDONLY);
	//STRCMP!!!
	if (fd < 0 || strcmp(".ber", &filename[ft_strlen(filename) - 4]))
	{
		ft_printf(".ber error\n");
		exit_message();
	}
	line = get_next_line(fd);
	if (!line)
		exit_message();
	width = ft_strlen(line) - 1; // to ignore newline
	height = 0;
	while (line)
	{
		if (width != ft_strlen(line) - 1) // same same if no new line, take -1 off
		{
			ft_printf("chkmap2\n");
			exit_message();
		}
		free(line);
		line = get_next_line(fd);
		height++;
	}
	close(fd);
	game->map_hight = height;
	return (width);
}

void	render_map(t_game *game, char *file)
{
	int 	fd;
	char	*line;
	int		i;

	game->map_lenght = check_map(game, file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error in render\n");
		exit_message();
	}
	game->map = (char **)malloc(sizeof(char *) * game->map_hight);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		game->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	//
	for (int i = 0; i < game->map_hight; i++)
	{
 	   ft_printf("%s", game->map[i]);
	}
	//
	free(line);
	close(fd);
	game->step_count = 0;
	valid_map(game);

}
