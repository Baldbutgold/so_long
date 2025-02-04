#include "so_long.h"

int	validate_file_extension(char *filename)
{
	char	*ext;

	ext = ft_strrchr(filename, '.');
	if (!ext)
		return (0);
	if (ext == filename)
		return (0);
	else if (*(ext - 1) == '/')
		return (0);
	else if (ft_strcmp(ext, ".ber") != 0)
		return(0);
	return (1);
}

/*remove the printf for a valid map and just run it */

int	main(int ac, char **av)
{
	int	fd;
	char	*extension;

	if (ac == 2)
	{
		fd = open(av[1], O_RDWR);
		if (fd == -1 || !validate_file_extension(av[1]))
			return (ft_printf("must provide a map!"));
		printf("validated file extension\n");
	}
	else
		ft_printf("Error, must provide a map!");
}
