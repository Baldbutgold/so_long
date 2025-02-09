/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:01:19 by ael-hadj          #+#    #+#             */
/*   Updated: 2025/02/03 16:02:31 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*# include "/usr/include/minilibx-linux/mlx.h"*/

# include "mlx/mlx.h"
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <stdlib.h>

# define TRUE 1
# define FALSE 0
# define TILE_SIZE 64
# define PLAYER "assets/player.xpm"
# define FLOOR "assets/floor.xpm"
# define ITEM "assets/item.xpm"
# define WALL "assets/wall.xpm"

typedef struct map{
	char	**grid;
	int	height;
	int	width;
} t_map; 

/*FUNCTION PROTOTYPES*/

void	free_grid(char **grid, int i);
int	validate_file(char *filename, int *lines_num);
int	process_line(char **grid, char *line, int i);
char	**map2grid(char *filename, int lines_num);
char	**init_program(char *filename);

#endif

/*typedef struct s_data*/
/*{*/
/*	void		*mlx_ptr; // MLX pointer*/
/*	void		*win_ptr; // MLX window pointer*/
/*	void		*textures[5]; // MLX image pointers (on the stack)*/
/*	t_map		*map; // Map pointer (contains map details - preferably kept on the stack)*/
/*}	t_data;*/
/**/
