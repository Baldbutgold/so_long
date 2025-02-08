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

void	free_grid(char **grid, int i)
{
	if (!grid)
		return ;
	while (i >= 0)
	{
		if (grid[i])
			free(grid[i]);
		i--;
	}
	free(grid);
	return;
}

int	init_program(char *filename, int fd, int *lines_num)
{
	char	*line;

	if (fd == -1 || !validate_file_extension(filename))
		return (ft_printf("Invalid File\n"), 0);
	else
	{
		while ((line = get_next_line(fd)) != NULL)
		{
			*lines_num = *lines_num + 1;
			free(line);
		}
		close(fd);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		fd;
	int	lines_num;
	char	**grid;
	int	i;
	size_t	line_len;
	char	*line;

	if (ac == 2)
	{
		fd = open(av[1], O_RDWR);
		lines_num = 0;
		i = 0;
		if (init_program(av[1], fd, &lines_num) == 0)
			return (1);
		grid = malloc((lines_num + 1) * sizeof(char *));
		fd = open(av[1], O_RDWR);
		while (i < lines_num)
		{
			line = get_next_line(fd);
			line_len = ft_strlen(line);
			if (line[line_len - 1] == '\n')
				line_len--;
			grid[i] = malloc((line_len + 1) * sizeof(char));
			ft_strlcpy(grid[i], line, line_len + 1);
			free(line);
			i++;
		}
		grid[i] = malloc(1);
		grid[i][0] = 0;
		free_grid(grid, i);
	}
	else
		ft_printf("Error, must provide a map!");
	close(fd);
	return (0);
}
