/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:08:36 by ael-hadj          #+#    #+#             */
/*   Updated: 2025/02/10 16:10:00 by ael-hadj         ###   ########.fr       */
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

void	init_images(t_map *map)
{
	int	width;
	int	height;

	map->imgs[P] = mlx_xpm_file_to_image(map->mlx, PLAYER, &width, &height);
	map->imgs[I] = mlx_xpm_file_to_image(map->mlx, ITEM, &width, &height);
	map->imgs[W] = mlx_xpm_file_to_image(map->mlx, WALL, &width, &height);
	map->imgs[F] = mlx_xpm_file_to_image(map->mlx, FLOOR, &width, &height);
	map->imgs[E] = mlx_xpm_file_to_image(map->mlx, EXIT, &width, &height);
	put_images_while(map);
}

void	update_pos(t_map *map, int x, int y)
{
	static int	moves;
	static int	is_exit;

	if (map->grid[x][y] == '1')
		return ;
	moves = moves + 1;
	ft_printf("moves : %d\n", moves);
	if (map->grid[x][y] == 'C')
	{
		map->collected = map->collected + 1;
		if (map->collected == map->item)
			is_exit = 1;
	}
	if (x == map->exit_x && y == map->exit_y && is_exit)
	{
		free_vars(map);
		return ;
	}
	map->grid[map->player_x][map->player_y] = '0';
	map->grid[x][y] = 'P';
	map->player_x = x;
	map->player_y = y;
	put_images_while(map);
}

int	key_handler(int keycode, t_map *map)
{
	if (keycode == XK_W || keycode == XK_w)
		update_pos(map, map->player_x - 1, map->player_y);
	if (keycode == XK_A || keycode == XK_a)
		update_pos(map, map->player_x, map->player_y - 1);
	if (keycode == XK_S || keycode == XK_s)
		update_pos(map, map->player_x + 1, map->player_y);
	if (keycode == XK_D || keycode == XK_d)
		update_pos(map, map->player_x, map->player_y + 1);
	if (keycode == XK_Escape)
		free_vars(map);
	return (TRUE);
}

int	display_map(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		return (FALSE);
	map->win = mlx_new_window(map->mlx, map->width * T,
			map->height * T, "game");
	if (!map->win)
		return (free(map->mlx), FALSE);
	map->collected = 0;
	init_images(map);
	mlx_hook(map->win, 2, 1L << 0, key_handler, map);
	mlx_hook(map->win, 17, 1L << 5, free_vars, map);
	mlx_loop(map->mlx);
	return (TRUE);
}
