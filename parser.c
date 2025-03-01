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

/*freeing the grid by reversing back*/

void	free_grid(char **grid, int i)
{
	if (!grid)
		return ;
	while (i >= 0)
	{
		free(grid[i]);
		i--;
	}
	free(grid);
	return ;
}

/* Validating file extension and getting the number of lines with gnl*/

int	validate_file(t_map *map)
{
	char	*line;
	char	*ext;
	int		fd;

	fd = open(map->filename, O_RDWR);
	ext = ft_strrchr(map->filename, '.');
	if (fd < 0 || !ext || ext == map->filename
		|| *(ext - 1) == '/' || ft_strcmp(ext, ".ber") != 0)
		return (ft_printf("%s%s", ERROR, FILE), FALSE);
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			map->height = map->height + 1;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (TRUE);
}

int	process_line(char **grid, char *line, int i)
{
	size_t	line_len;

	line_len = ft_strlen(line);
	if (line[line_len - 1] == '\n')
		line_len = line_len - 1;
	grid[i] = malloc(line_len + 1);
	if (!grid[i])
		return (free(line), free_grid(grid, i), FALSE);
	ft_strlcpy(grid[i], line, line_len + 1);
	return (TRUE);
}

/*saving the processed line to a grid that will be later on verified*/
char	**map2grid(char *filename, int height)
{
	int		fd;
	int		i;
	char	**grid;
	char	*line;

	grid = malloc((height + 1) * sizeof(char *));
	if (!grid)
		return (NULL);
	i = 0;
	fd = open(filename, O_RDWR);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!process_line(grid, line, i))
			return (close(fd), NULL);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	grid[i] = 0;
	close(fd);
	return (grid);
}

char	**init_program(t_map *map)
{
	char	**grid;

	map->item = 0;
	map->width = 0;
	map->height = 0;
	if (!validate_file(map))
		return (NULL);
	if (map->height <= 2)
		return (ft_printf("%s%s", ERROR, SHORT), NULL);
	grid = map2grid(map->filename, map->height);
	if (!grid)
		return (free_grid(grid, map->height - 1),
			ft_printf("%s%s", ERROR, FAIL), NULL);
	if (!map_check(grid, map))
		return (free_grid(grid, map->height - 1), NULL);
	return (grid);
}
