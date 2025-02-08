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

/*int	validate_file_extension(char *filename)*/
/*{*/
/*	char	*ext;*/
/**/
/*	ext = ft_strrchr(filename, '.');*/
/*	if (!ext)*/
/*		return (0);*/
/*	if (ext == filename)*/
/*		return (0);*/
/*	else if (*(ext - 1) == '/')*/
/*		return (0);*/
/*	else if (ft_strcmp(ext, ".ber") != 0)*/
/*		return (0);*/
/*	return (1);*/
/*}*/

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

int	init_program(char *filename, int *lines_num)
{
	char	*line;
	char	*ext;
	int		fd;

	fd = open(filename, O_RDWR);
	ext = ft_strrchr(filename, '.');
	if (fd < 0 || !ext || ext == filename
		|| *(ext - 1) == '/' || ft_strcmp(ext, ".ber") != 0)
		return (ft_printf("Invalid File\n"), 0);
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
	return (1);
}

int	process_line(char **grid, char *line, int i)
{
	size_t	line_len;

	line_len = ft_strlen(line);
	if (line[line_len - 1] == '\n')
		line_len = line_len - 1;
	grid[i] = malloc(line_len + 1);
	if (!grid[i])
		return (free(line), free_grid(grid, i), 0);
	ft_strlcpy(grid[i], line, line_len + 1);
	return (1);
}

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

int	main(int ac, char **av)
{
	char	**grid;
	int		lines_num;

	if (ac == 2)
	{
		lines_num = 0;
		if (init_program(av[1], &lines_num) == 0)
			return (1);
		grid = map2grid(av[1], lines_num);
		if (!grid)
			return (ft_printf("There is an error with the map"), 1);
	}
	else
		ft_printf("Error, must provide a map!");
	return (0);
}

/*test if grid has something and free*/
/*int	j = 0;*/
/*while (grid[j] != 0)*/
/*	ft_printf("%s\n", grid[j++]);*/
/*free_grid(grid, j);*/
