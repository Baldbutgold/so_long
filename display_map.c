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
	if (map->grid[i][j] == 'E')
		mlx_put_image_to_window(map->mlx, map->win,
			map->imgs[E], j * T, i * T);
	if (map->grid[i][j] == 'P')
		mlx_put_image_to_window(map->mlx, map->win,
			  map->imgs[P], j * T, i * T);
}

void	put_player_on_exit(t_map *map)
{

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
	if (map->grid[x][y] == 'C')
	{
		map->collected = map->collected + 1;
		if (map->collected == map->item)
			is_exit = 1;
	}
	if (map->grid[x][y] == 'E' || map->grid[map->player_x][map->player_y] == 'E')
	{
		if (is_exit == 1)
			mlx_destroy_display(map->mlx);
		else
		{
		}
	}
	map->grid[x][y] = 'P';
	map->grid[map->player_x][map->player_y] = '0';
	map->player_x = x;
	map->player_y = y;
	moves = moves + 1;
	int	j = 0;
	while (map->grid[j])
		ft_printf("%s\n", map->grid[j++]);
	ft_printf("moves : %d\n", moves);
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
		ft_printf("escaped pressed\n");
	return (0);
}
/*close handler*/

int	display_map(char **grid, t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		return (FALSE);
	map->win = mlx_new_window(map->mlx, map->width * T, map->height * T, "game");
	if (!map->win)
		return (free(map->mlx), free_grid(grid, map->height - 1), FALSE);
	init_images(map);
	map->collected = 0;
	mlx_hook(map->win, 2, 1L<<0, key_handler, map);
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
