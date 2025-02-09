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
	char	**grid;

	if (ac == 2)
	{
		grid = init_program(av[1]);
		if (!grid)
			return (1);
		int	j = 0;
		while (grid[j] != 0)
			ft_printf("%s\n", grid[j++]);
		free_grid(grid, j);
	}
	else
		return (ft_printf("Error, must provide a map!"), 0);
}

		/*ft_printf("I am here");*/
/*int	j = 0;*/
/*while (grid[j] != 0)*/
/*	ft_printf("%s\n", grid[j++]);*/
/*free_grid(grid, j);*/
