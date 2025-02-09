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

int	validate_file(char *filename, int *lines_num)
{
	char	*line;
	char	*ext;
	int		fd;

	fd = open(filename, O_RDWR);
	ext = ft_strrchr(filename, '.');
	if (fd < 0 || !ext || ext == filename
		|| *(ext - 1) == '/' || ft_strcmp(ext, ".ber") != 0)
		return (ft_printf("Invalid File\n"), FALSE);
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			*lines_num = *lines_num + 1;
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
char	**map2grid(char *filename, int lines_num)
{
	int		fd;
	int		i;
	char	**grid;
	char	*line;

	grid = malloc((lines_num + 1) * sizeof(char *));
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

char	**init_program(char *filename)
{
	char	**grid;
	int		lines_num;

	lines_num = 0;
	if (validate_file(filename, &lines_num) == 0)
		return (NULL);
	grid = map2grid(filename, lines_num);
	if (!grid)
		return (ft_printf("Something went wrong\n"), NULL);
	return (grid);
}
