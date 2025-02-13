/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:20:15 by ael-hadj          #+#    #+#             */
/*   Updated: 2025/02/09 11:26:06 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

int	char_check(char **grid, t_map *map, int i, int j)
{
	if (!ft_strchr("01EPC", grid[i][j]))
		return (ft_printf("%s%s", ERROR, INV_CHAR), FALSE);
	if (grid[i][j] == 'C')
		map->item = map->item + 1;
	if (grid[i][j] == 'P')
	{
		map->player_x = i;
		map->player_y = j;
		map->player = map->player + 1;
	}
	if (grid[i][j] == 'E')
	{
		map->exit_x = i;
		map->exit_y = j;
		map->exit = map->exit + 1;
	}
	if (grid[0][j] != '1' || grid[map->height - 1][j] != '1')
		return (ft_printf("%s%s", ERROR, BORDERS), FALSE);
	return (TRUE);
}

int	error_display(int exit, int player, int item)
{
	if (exit != 1)
		return (ft_printf("%s%s", ERROR, E_ERROR), FALSE);
	if (player != 1)
		return (ft_printf("%s%s", ERROR, P_ERROR), FALSE);
	if (item == 0)
		return (ft_printf("%s%s", ERROR, I_ERROR), FALSE);
	return (TRUE);
}

int	init_check(char **grid, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		if (ft_strlen(grid[i]) != map->width
			|| (grid[i][0] != '1' || grid[i][map->width - 1] != '1'))
			return (ft_printf("%s%s", ERROR, BORDERS), FALSE);
		while (grid[i][j])
		{
			if (!char_check(grid, map, i, j))
				return (FALSE);
			j++;
		}
		i++;
	}
	if (!(error_display(map->exit, map->player, map->item)))
		return (FALSE);
	return (TRUE);
}

void	flood_fill(char **grid, t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || grid[x] == 0
		|| grid[x][y] == '1' || grid[x][y] == 'V')
		return ;
	if (grid[x][y] == 'C')
		map->collected++;
	if (grid[x][y] == 'E')
		map->found_exit = 1;
	grid[x][y] = 'V';
	flood_fill(grid, map, x + 1, y);
	flood_fill(grid, map, x - 1, y);
	flood_fill(grid, map, x, y + 1);
	flood_fill(grid, map, x, y - 1);
}

int	map_check(char **grid, t_map *map)
{
	char	**temp_grid;

	map->exit = 0;
	map->found_exit = 0;
	map->player = 0;
	map->width = ft_strlen(grid[0]);
	map->collected = 0;
	if (!(init_check(grid, map)))
		return (FALSE);
	temp_grid = map2grid(map->filename, map->height);
	if (!temp_grid)
		free_grid(temp_grid, map->height - 1);
	flood_fill(temp_grid, map, map->player_x, map->player_y);
	free_grid(temp_grid, map->height - 1);
	if (!(map->collected == map->item && map->found_exit == 1))
		return (free_grid(grid, map->height - 1),
			ft_printf("%s%s", ERROR, INV_MAP), FALSE);
	return (TRUE);
}
