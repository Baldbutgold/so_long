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

void	put_images(t_map *map, t_mlx *mlx)
{
	int	j;
	int	i;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			mlx_put_image_to_window(mlx->mlx, mlx->win,
				map->imgs[F], j * T, i * T);
			if (map->grid[i][j] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win, map->imgs[W], j * T, i * T);
			if (map->grid[i][j] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win,
					map->imgs[I], j * T, i * T);
			if (map->grid[i][j] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->win,
					map->imgs[E], j * T, i * T);
			if (map->grid[i][j] == 'P')
				mlx_put_image_to_window(mlx->mlx, mlx->win,
					map->imgs[P], j * T, i * T);
			j++;
		}
		i++;
	}
}
void	put_images_2(t_map *map, t_mlx *mlx)
{
	int	j;
	int	i;

	i = 0;
	while (map->grid[i])
	{
		printf("%s\n", map->grid[i]);
		j = 0;
		while (map->grid[i][j])
		{
			mlx_put_image_to_window(mlx->mlx, mlx->win,
				map->imgs[F], j * T, i * T);
			ft_printf("\nIm here\n");
			if (map->grid[i][j] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win,
					map->imgs[W], j * T, i * T);
			if (map->grid[i][j] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win,
					map->imgs[I], j * T, i * T);
			if (map->grid[i][j] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->win,
					map->imgs[E], j * T, i * T);
			if (map->grid[i][j] == 'P')
				mlx_put_image_to_window(mlx->mlx, mlx->win,
					map->imgs[P], j * T, i * T);
			j++;
		}
		i++;
	}
}

void	init_images(t_map *map, t_mlx *mlx)
{
	int	width;
	int	height;

	map->imgs[P] = mlx_xpm_file_to_image(mlx->mlx, PLAYER, &width, &height);
	map->imgs[I] = mlx_xpm_file_to_image(mlx->mlx, ITEM, &width, &height);
	map->imgs[W] = mlx_xpm_file_to_image(mlx->mlx, WALL, &width, &height);
	map->imgs[F] = mlx_xpm_file_to_image(mlx->mlx, FLOOR, &width, &height);
	map->imgs[E] = mlx_xpm_file_to_image(mlx->mlx, EXIT, &width, &height);
	put_images(map, mlx);
}

void	update_pos(t_map *map, t_mlx *mlx, int x, int y)
{
	map->grid[map->player_x][map->player_y] = '0';
	map->grid[x][y] = 'P';
	map->player_x = x;
	map->player_y = y;
	int	i = 0;
	ft_printf("this is the updated position\n");
	while (map->grid[i])
		printf("%s\n", map->grid[i++]);
	ft_printf("\n");
	put_images_2(map, mlx);
}

/*// a function to update */
int	key_handler(int keycode, t_map *map, t_mlx *mlx)
{
	static int	moves;
	ft_printf("\n");
	if (keycode == XK_W || keycode == XK_w)
		update_pos(map, mlx, map->player_x - 1, map->player_y);
	if (keycode == XK_A || keycode == XK_a)
		update_pos(map, mlx, map->player_x, map->player_y - 1);
	if (keycode == XK_S || keycode == XK_s)
		update_pos(map, mlx, map->player_x + 1, map->player_y);
	if (keycode == XK_D || keycode == XK_d)
		update_pos(map, mlx, map->player_x, map->player_y + 1);
	if (keycode == XK_Escape)
		ft_printf("escaped pressed\n");
	moves = moves + 1;
	ft_printf("player is at %d %d\nmoves %d\n", map->player_x, map->player_y, moves);
	return (0);
}

int	display_map(char **grid, t_map *map)
{
	t_mlx	mlx;


	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		return (FALSE);
	mlx.win = mlx_new_window(mlx.mlx, map->width * T, map->height * T, "game");
	if (!mlx.win)
		return (free(mlx.mlx), free_grid(grid, map->height - 1), FALSE);
	init_images(map, &mlx);
	mlx_hook(mlx.win, 2, 1L<<0, key_handler, map);
	mlx_loop(mlx.mlx);
	return (TRUE);
}
/* free when destroyed, esc or x & what is width & height?*/
/*	sleep(10);*/
/*	mlx_destroy_window(mlx_ptr, win_ptr);*/
/*	mlx_destroy_display(mlx_ptr);*/
/*	free(mlx_ptr);*/

/*int on_destroy(t_data *data)*/
/*{*/
/*	mlx_destroy_window(data->mlx_ptr, data->win_ptr);*/
/*	mlx_destroy_display(data->mlx_ptr);*/
/*	free(data->mlx_ptr);*/
/*	exit(0);*/
/*	return (0);*/
/*}*/
/**/
/*int on_keypress(int keysym, t_data *data)*/
/*{*/
/*	(void)data;*/
/*	printf("Pressed key: %d\\n", keysym);*/
/*	return (0);*/
/*}*/
