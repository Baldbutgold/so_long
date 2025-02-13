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
# include <X11/X.h>
# include <X11/keysym.h>

/*Error Messages*/

# define ERROR "Error\n"
# define FILE "Invalid File path or extension\n"
# define FAIL "Malloc Failed Try again\n"
# define SHORT "Map is too short\n"
# define FORMAT "wrong format, try: ./so_long filename\n"
# define INV_CHAR "Invalid characters, try only 01EPC\n"
# define BORDERS "The Borders are not enclosed\n"
# define E_ERROR "Exit error\n"
# define P_ERROR "Player error\n"
# define I_ERROR "Item error\n"
# define INV_MAP "Map is Impossible\n"
# define TRUE 1
# define FALSE 0
# define T 64
# define PLAYER "textures/player.xpm"
# define EXIT "textures/exit.xpm"
# define FLOOR "textures/floor.xpm"
# define ITEM "textures/item.xpm"
# define WALL "textures/wall.xpm"

# define P 0
# define E 1
# define F 2
# define I 3
# define W 4

typedef struct s_map
{
	char	**grid;
	char	*filename;
	size_t	width;
	int		player;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		exit;
	int		height;
	int		item;
	int		collected;
	int		found_exit;
	int		fd;
	void		*imgs[5];
	void	*mlx;
	void	*win;
}	t_map;

/*FUNCTION PROTOTYPES*/

void	free_grid(char **grid, int i);
int		validate_file(t_map *map);
int		process_line(char **grid, char *line, int i);
char	**map2grid(char *filename, int lines_num);
char	**init_program(t_map *map);
int		map_check(char **grid, t_map *map);
int		display_map(char **grid, t_map *map);

#endif
