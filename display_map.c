
#include "so_long.h"
#include "libft/libft.h"

int	display_map(char **grid, t_map *map)
{
	t_mlx	mlx;
	t_img	img;
	int	width;
	int	height;

	int i, (j);
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		return (FALSE);
	mlx.win = mlx_new_window(mlx.mlx, (int)map->width * TILE_SIZE, map->height * TILE_SIZE, "game");
	if (!mlx.win)
		return (free(mlx.mlx), FALSE);
	// mlx hook to register key press
	// i think i need to check if those failed to free them or something like that
	img.sprites[P] = mlx_xpm_file_to_image(mlx.mlx, PLAYER, &width, &height);
	img.sprites[I] = mlx_xpm_file_to_image(mlx.mlx, ITEM, &width, &height);
	img.sprites[W] = mlx_xpm_file_to_image(mlx.mlx, WALL, &width, &height);
	img.sprites[F] = mlx_xpm_file_to_image(mlx.mlx, FLOOR, &width, &height);
	img.sprites[E] = mlx_xpm_file_to_image(mlx.mlx, EXIT, &width, &height);
	i = 0;
	while (grid[i])
	{
		j = 0;
		while(grid[i][j])
		{
			if (grid[i][j] == '1')
				mlx_put_image_to_window(mlx.mlx, mlx.win, img.sprites[W], j * TILE_SIZE, i * TILE_SIZE);
			if (grid[i][j] == '0')
				mlx_put_image_to_window(mlx.mlx, mlx.win, img.sprites[F], j * TILE_SIZE, i * TILE_SIZE);
			if (grid[i][j] == 'C')
				mlx_put_image_to_window(mlx.mlx, mlx.win, img.sprites[I], j * TILE_SIZE, i * TILE_SIZE);
			if (grid[i][j] == 'P')
				mlx_put_image_to_window(mlx.mlx, mlx.win, img.sprites[P], j * TILE_SIZE, i * TILE_SIZE);
			if (grid[i][j] == 'E')
				mlx_put_image_to_window(mlx.mlx, mlx.win, img.sprites[E], j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
	/*mlx_put_image_to_window(mlx.mlx, mlx.win, img._ptr, 0, 0);*/
	mlx_loop(mlx.mlx);

	return (TRUE);
}
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
