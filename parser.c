/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:59:27 by ael-hadj          #+#    #+#             */
/*   Updated: 2025/02/04 19:59:31 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
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
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	int	lines_num;
	char	**grid;
	int	i;

	if (ac == 2)
	{
		fd = open(av[1], O_RDWR);
		if (fd == -1 || !validate_file_extension(av[1]))
			return (ft_printf("must provide a map!"), 0);
		lines_num = 0;
		while ((line = get_next_line(fd)) != NULL)
		{
			lines_num++;
			free(line);
		}
		printf("lines are %d\n", lines_num);
		close(fd);
		fd = open(av[1], O_RDWR);
		grid = malloc(lines_num + 1);
		i = 0;
		while (i < lines_num)
		{
			line = get_next_line(fd);
			grid[i] = malloc(ft_strlen(line));
			ft_strlcpy(grid[i], line, ft_strlen(line) - 1);
			printf("i is %d on grid %s\n", i, grid[i]);
			free(line);
			i++;
		}
		grid[i] = malloc(1);
		grid[i][0] = 0;
	}
	else
		ft_printf("Error, must provide a map!");
}
