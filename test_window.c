#include "so_long.h"
#include <minilibx-linux/mlx.h>

int	main()
{
	void	*ptr;
	mlx_init();
	mlx_new_window(ptr, 32, 32, "game");
}
