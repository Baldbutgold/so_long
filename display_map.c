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

void	put_images(char **grid, t_mlx *mlx, t_img *img, int i)
{
	int	j;

	j = 0;
	while (grid[i][j])
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			img->sprites[F], j * T, i * T);
		if (grid[i][j] == '1')
			mlx_put_image_to_window(mlx->mlx, mlx->win,
				img->sprites[W], j * T, i * T);
		if (grid[i][j] == 'C')
			mlx_put_image_to_window(mlx->mlx, mlx->win,
				img->sprites[I], j * T, i * T);
		if (grid[i][j] == 'E')
			mlx_put_image_to_window(mlx->mlx, mlx->win,
				img->sprites[E], j * T, i * T);
		if (grid[i][j] == 'P')
			mlx_put_image_to_window(mlx->mlx, mlx->win,
				img->sprites[P], j * T, i * T);
		j++;
	}
}

void	init_images(char **grid, t_img *img, t_mlx *mlx)
{
	int	width;
	int	height;
	int	i;

	img->sprites[P] = mlx_xpm_file_to_image(mlx->mlx, PLAYER, &width, &height);
	img->sprites[I] = mlx_xpm_file_to_image(mlx->mlx, ITEM, &width, &height);
	img->sprites[W] = mlx_xpm_file_to_image(mlx->mlx, WALL, &width, &height);
	img->sprites[F] = mlx_xpm_file_to_image(mlx->mlx, FLOOR, &width, &height);
	img->sprites[E] = mlx_xpm_file_to_image(mlx->mlx, EXIT, &width, &height);
	i = 0;
	while (grid[i])
	{
		put_images(grid, mlx, img, i);
		i++;
	}
}

// a function to update 
int	key_handler(int keycode, t_map *map)
{
	if (keycode == XK_D)
		ft_printf("d pressed\n");
		/*map->player_x += 1;*/
	if (keycode == XK_A)
		ft_printf("a pressed\n");
		/*map->player_x -= 1;*/
	if (keycode == XK_S)
		ft_printf("s pressed\n");
		/*map->player_y -= 1;*/
	if (keycode == XK_W)
		ft_printf("w pressed\n");
		/*map->player_y += 1;*/
	if (keycode == XK_Escape)
		ft_printf("escaped pressed\n");
	return (0);
}

int	key_closer(int keycode, t_map *map)
{
	ft_printf("close map");
	return (0);
}

int	display_map(char **grid, t_map *map)
{
	t_mlx	mlx;
	t_img	img;

	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		return (FALSE);
	mlx.win = mlx_new_window(mlx.mlx, map->width * T, map->height * T, "game");
	if (!mlx.win)
		return (free(mlx.mlx), free_grid(grid, map->height - 1), FALSE);
	init_images(grid, &img, &mlx);
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
