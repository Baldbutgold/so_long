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

/*w : 119*/
/*a : 97*/
/*s : 115*/
/*d : 100*/

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

#include <X11/X.h>
#include <X11/keysym.h>

# define TRUE 1
# define FALSE 0
# define TILE_SIZE 64
# define PLAYER "assets/player.xpm"
# define EXIT "assets/exit.xpm"
# define FLOOR "assets/floor.xpm"
# define ITEM "assets/item.xpm"
# define WALL "assets/wall.xpm"
# define P 0
# define E 1
# define F 2
# define I 3
# define W 4

typedef struct s_map
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
	int		collected;
}	t_map;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_imgs
{
	void	*sprites[5];
	/*void	*player_ptr;*/
	/*void	*floor_ptr;*/
	/*void	*item_ptr;*/
	/*void	*wall_ptr;*/
	/*void	*exit_ptr;*/
}	t_img;

/*FUNCTION PROTOTYPES*/

void	free_grid(char **grid, int i);
int		validate_file(char *filename, t_map *map);
int		process_line(char **grid, char *line, int i);
char	**map2grid(char *filename, int lines_num);
char	**init_program(char *filename, t_map *map);
int		map_check(char **grid, t_map *map);
int	display_map(char **grid, t_map *map);

#endif

/*typedef struct s_data*/
/*{*/
/*	void		*mlx_ptr; // MLX pointer*/
/*	void		*win_ptr; // MLX window pointer*/
/*	void		*textures[5]; // MLX image pointers (on the stack)*/
/*	t_map		*map; // Map pointer (contains map details - preferably kept on the stack)*/
/*}	t_data;*/
/**/
