/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 09:05:48 by ael-hadj          #+#    #+#             */
/*   Updated: 2025/02/15 09:05:59 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_vars(t_map *map)
{
	free_grid(map->grid, map->height -1);
	mlx_destroy_image(map->mlx, map->imgs[P]);
	mlx_destroy_image(map->mlx, map->imgs[I]);
	mlx_destroy_image(map->mlx, map->imgs[E]);
	mlx_destroy_image(map->mlx, map->imgs[W]);
	mlx_destroy_image(map->mlx, map->imgs[F]);
	mlx_destroy_window(map->mlx, map->win);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	exit(0);
	return (TRUE);
}

void	put_images(t_map *map, int i, int j)
{
	if (map->grid[i][j] == '0')
		mlx_put_image_to_window(map->mlx, map->win,
			map->imgs[F], j * T, i * T);
	if (map->grid[i][j] == '1')
		mlx_put_image_to_window(map->mlx, map->win,
			map->imgs[W], j * T, i * T);
	if (map->grid[i][j] == 'C')
		mlx_put_image_to_window(map->mlx, map->win,
			map->imgs[I], j * T, i * T);
	mlx_put_image_to_window(map->mlx, map->win,
		map->imgs[E], map->exit_y * T, map->exit_x * T);
	mlx_put_image_to_window(map->mlx, map->win,
		map->imgs[P], map->player_y * T, map->player_x * T);
}

void	put_images_while(t_map *map)
{
	int	j;
	int	i;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			put_images(map, i, j);
			j++;
		}
		i++;
	}
}
