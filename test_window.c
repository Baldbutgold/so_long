#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "so_long.h"

/*w : 119*/
/*a : 97*/
/*s : 115*/
/*d : 100*/

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
} t_data;

typedef struct s_images
{
	void	*player_ptr;
	void	*floor_ptr;
	void	*item_ptr;
	void	*wall_ptr;
} t_images;

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("Pressed key: %d\\n", keysym);
	return (0);
}

int main(void)
{
	t_data		data;
	t_images	images;
	int	width;
	int	height;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "hi :)");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);

	// Register key release hook
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);

	// Register destroy hook
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	
	images.player_ptr = mlx_xpm_file_to_image(data.mlx_ptr, PLAYER, &width, &height);
	images.item_ptr = mlx_xpm_file_to_image(data.mlx_ptr, ITEM, &width, &height);
	images.wall_ptr = mlx_xpm_file_to_image(data.mlx_ptr, WALL, &width, &height);
	images.floor_ptr = mlx_xpm_file_to_image(data.mlx_ptr, FLOOR, &width, &height);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, images.floor_ptr, 0, 0);
	// Loop over the MLX pointer
	mlx_loop(data.mlx_ptr);
	return (0);
}
/*#include "so_long.h"*/
/*int	main()*/
/*{*/
/*	void	*mlx_ptr;*/
/*	void	*win_ptr;*/
/**/
/*	mlx_ptr = mlx_init();*/
/*	if (!mlx_ptr)*/
/*		return (1);*/
/*	win_ptr = mlx_new_window(mlx_ptr, 600, 800, "game");*/
/*	if (!win_ptr)*/
/*		return (free(mlx_ptr), 1);*/
/*	sleep(10);*/
/*	mlx_destroy_window(mlx_ptr, win_ptr);*/
/*	mlx_destroy_display(mlx_ptr);*/
/*	free(mlx_ptr);*/
/*	return (0);*/
/*}*/
