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

#include "mlx/mlx.h"
#include "so_long.h"
#include "libft/libft.h"

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
		mlx_destroy_display(map->mlx);
		return ;
	}
	map->grid[map->player_x][map->player_y] = '0';
	map->grid[x][y] = 'P';
	map->player_x = x;
	map->player_y = y;
	put_images_while(map);
}

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
	{
		free_vars(map);
	}
	return (TRUE);
}

int	display_map(char **grid, t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		return (FALSE);
	map->win = mlx_new_window(map->mlx, map->width * T, map->height * T, "game");
	if (!map->win)
		return (free(map->mlx), free_grid(grid, map->height - 1), FALSE);
	map->collected = 0;
	init_images(map);
	mlx_hook(map->win, 2, 1L<<0, key_handler, map);
	mlx_hook(map->win, 17, 1L<<5, free_vars, map);
	mlx_loop(map->mlx);
	return (TRUE);
}
/* free when destroyed, esc or x*/
/*	map_destroy_window(mlx_ptr, win_ptr);*/
/*	map_destroy_display(mlx_ptr);*/
/*	free(map_ptr);*/

/*int on_destroy(t_data *data)*/
/*{*/
/*	map_destroy_window(data->mlx_ptr, data->win_ptr);*/
/*	map_destroy_display(data->mlx_ptr);*/
/*	free(data->map_ptr);*/
/*	exit(0);*/
/*	return (0);*/
/*}*/
