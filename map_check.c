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

int	map_check(char **grid, int height, size_t *width, int *item)
{
	int	i;
	int	j;
	int	exit;
	int	player;

	i = 0;
	exit = 0;
	player = 0;
	*width = ft_strlen(grid[0]);
	while (grid[i])
	{
		j = 0;
		if (ft_strlen(grid[i]) != *width
			|| (grid[i][0] != '1' && grid[i][*width] != '1'))
			return (ft_printf("map invalid\n"), FALSE);
		while (grid[i][j])
		{
			if (!ft_strchr("01EPC", grid[i][j]))
				return (ft_printf("invalid character\n"), FALSE);
			else if (grid[i][j] == 'C')
				*item = *item + 1;
			else if (grid[i][j] == 'P')
				player = player + 1;
			else if (grid[i][j] == 'E')
				exit = exit + 1;
			if (grid[0][j] != '1' && grid[height - 1][j] != '1')
				return (ft_printf("map is not valid\n"), FALSE);
			j++;
		}
		i++;
	}
	ft_printf("player %d exit %d item %d\n", player, exit, *item);
	if (exit > 1 || exit == 0 || player > 1 || player == 0 || item == 0)
		return (ft_printf("map is not valid\n"), FALSE);
	return (TRUE);
}

/*ft_printf("I am here");*/
/*int	j = 0;*/
/*while (grid[j] != 0)*/
/*	ft_printf("%s\n", grid[j++]);*/
/*free_grid(grid, j);*/
