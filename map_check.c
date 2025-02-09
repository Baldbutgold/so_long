/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:35:35 by ael-hadj          #+#    #+#             */
/*   Updated: 2025/02/09 10:42:31 by ael-hadj         ###   ########.fr       */ /*                                                                            */ /* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

int	check_map(char **grid, int height)
{
	size_t	width;
	int	i;
	int	j;

	i = 0;
	j = 0;
	width = ft_strlen(grid[0]);
	// here there might some problems |||| check the -1 for width and height
	while (grid[0][j] == '1' && grid[height - 1][j] == '1')
		j++;
	if (j != width)
		return (ft_printf("map is not valid\n"), FALSE);
	while (grid[i])
	{
		if (ft_strlen(grid[i]) != width)
			return (ft_printf("map invalid\n"), FALSE);
		if (grid[i][0] != '1' && grid[i][width] != '1')
			return (ft_printf("map is not valid\n"), FALSE);
		i++;
	}
	return (TRUE);
}

/*ft_printf("I am here");*/
/*int	j = 0;*/
/*while (grid[j] != 0)*/
/*	ft_printf("%s\n", grid[j++]);*/
/*free_grid(grid, j);*/
