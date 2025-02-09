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

/*0 for an empty space,*/
/*1 for a wall,*/
/*C for a collectible,*/
/*E for a map exit,*/
/*P for the player’s starting position.*/

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

typedef struct map
{
	char	**grid;
	size_t	width;
	int		player;
	int		player_x;
	int		player_y;
	int		exit;
	int		exit_x;
	int		exit_y;
	int		height;
	int		item;
}	t_map;

/*FUNCTION PROTOTYPES*/

void	free_grid(char **grid, int i);
int		validate_file(char *filename, t_map *map);
int		process_line(char **grid, char *line, int i);
char	**map2grid(char *filename, int lines_num);
char	**init_program(char *filename, t_map *map);
int		map_check(char **grid, t_map *map);

#endif

/*typedef struct s_data*/
/*{*/
/*	void		*mlx_ptr; // MLX pointer*/
/*	void		*win_ptr; // MLX window pointer*/
/*	void		*textures[5]; // MLX image pointers (on the stack)*/
/*	t_map		*map; // Map pointer (contains map details - preferably kept on the stack)*/
/*}	t_data;*/
/**/
