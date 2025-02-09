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
		return (ft_printf("invalid character only 01EPC\n"), FALSE);
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
		return (ft_printf("map is not enclosed\n"), FALSE);
	return (TRUE);
}

int	error_display(int exit, int player, int item)
{
	if (exit != 1)
		return (ft_printf("Exit error\n"), FALSE);
	if (player != 1)
		return (ft_printf("Player error\n"), FALSE);
	if (item == 0)
		return (ft_printf("at least one item required\n"), FALSE);
	return (TRUE);
}

int	map_check(char **grid, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->exit = 0;
	map->player = 0;
	map->width = ft_strlen(grid[0]);
	while (grid[i])
	{
		j = 0;
		if (ft_strlen(grid[i]) != map->width
			|| (grid[i][0] != '1' || grid[i][map->width - 1] != '1'))
			return (ft_printf("map is not enclosed\n"), FALSE);
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
