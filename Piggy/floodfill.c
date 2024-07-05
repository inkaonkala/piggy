#include "solong.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static void	free_map(char **map, int h)
{
	int	i;
	
	i = 0;
    while (i < h) 
	{
        free(map[i]);
        i++;
    }
}

static void doit(char **tab, t_point size, t_point current, char filler) 
{
    if (current.y < 0 || current.y >= size.y || current.x < 0 || current.x >= size.x)
        return;
    if (tab[current.y][current.x] != '0' && tab[current.y][current.x] != 'P' && tab[current.y][current.x] != 'C')
        return;
    
    tab[current.y][current.x] = filler;

    doit(tab, size, (t_point){current.x - 1, current.y}, filler);
    doit(tab, size, (t_point){current.x + 1, current.y}, filler);
    doit(tab, size, (t_point){current.x, current.y - 1}, filler);
    doit(tab, size, (t_point){current.x, current.y + 1}, filler);
}

static void flood_fill(char **tab, t_point size, t_point begin) 
{
    doit(tab, size, begin, 'F');
}

void impossible_map(t_game *game) 
{
    char **map = game->map;
    int map_hight = game->map_hight;
    int map_lenght = game->map_lenght;

    char **copy = (char **)malloc(map_hight * sizeof(char *));
    int i = 0;
    while (i < map_hight) 
	{
        copy[i] = (char *)malloc((map_lenght + 1) * sizeof(char));
        int j = 0;
        while (j < map_lenght) 
		{
            copy[i][j] = map[i][j];
            j++;
        }
        i++;
    }

	//void find_start()
    // Find the starting point
    int startX = -1, startY = -1;
    i = 0;
    while (i < map_hight) 
	{
        int j = 0;
        while (j < map_lenght) 
		{
            if (map[i][j] == 'P') 
			{
                startX = j;
                startY = i;
                break;
            }
            j++;
        }
        if (startX != -1) break;
        i++;
    }

    if (startX == -1 || startY == -1) 
	{
		free_map(copy, game->map_hight);
        ft_printf("Error:\nYou have blocked me!\n");
        exit(1);
    }

    // Perform flood fill
    t_point size = {map_lenght, map_hight};
    t_point begin = {startX, startY};
    flood_fill(copy, size, begin);

	//void	check_F()

    i = 0;
    while (i < map_hight) 
	{
        int j = 0;
        while (j < map_lenght) 
		{
            if (map[i][j] == 'C' && copy[i][j] != 'F') 
			{
               	free_map(copy, game->map_hight);
        		ft_printf("Error:\nYou have blocked me!\n");
        		exit(1);
            }
            j++;
        }
        i++;
    }
	free_map(copy, game->map_hight);
}