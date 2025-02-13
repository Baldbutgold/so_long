/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 09:59:39 by ael-hadj          #+#    #+#             */
/*   Updated: 2025/02/09 09:59:54 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

int	main(int ac, char **av)
{
	t_map	map;

	if (ac == 2)
	{
		map.filename = av[1];
		map.grid = init_program(&map);
		if (!map.grid)
			return (1);
		display_map(map.grid, &map);
		free_grid(map.grid, map.height - 1);
	}
	else
		return (ft_printf("%s%s", ERROR, FORMAT), 1);
}

/*ft_printf("I am here");*/
/*int	j = 0;*/
/*while (map.grid[j] != 0)*/
/*	ft_printf("%s\n", map.grid[j++]);*/
/*free_map.grid(grid, j);*/
