#include "mlx/mlx.h"
#include "so_long.h"

int	main()
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();

	mlx_win = mlx_new_window(mlx, 900, 900, "not so long after all");
	mlx_loop(mlx);
}
