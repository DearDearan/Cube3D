/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 06:11:11 by lifranco          #+#    #+#             */
/*   Updated: 2026/10/12 14:33:56 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "peggle_deluxe/include/peggle_deluxe.h"
# define EXT_ERR "Error: Invalid Map Extension. it's \".cub\".\n"
# define FLE_ERR "Error: An Error occured while opening the file.\n"
# define INV_ERR "Error: The map is invalid!\n"
# define CLR_ERR "Invalid Color detected. Make sure it's between 0 and 255.\n"

typedef struct s_map		t_map;
typedef struct s_context	t_ctx;
typedef struct s_castdata	t_cast;
typedef struct s_castdata	t_cast;
typedef struct s_context	t_ctx;
typedef struct s_draw		t_draw;
typedef struct s_images		t_img;
typedef struct s_intvec		t_vec2i;
typedef struct s_floatvec	t_vec2;

t_map		*validate_map(char *map, t_vec2 *player,
				t_vec2 *dir, t_vec2 *plane);
bool		parse_map(char *filename, t_ctx *res);
t_map		*make_map(char *map, uintmax_t *ppos);
bool		parse_text_path(t_ctx *context, char **text_paths);
bool		check_single_line(char *tmp, char *map, size_t w);
bool		check_lines(char *map, size_t w);
bool		check_walls(t_map *map_struct);
mlx_color	get_rgb(char *r, char *g, char *b, t_map *map);
void		init_map_width_height(char *map, t_map *resmap);
bool		handle_matches(char **matches, t_ctx *res);
bool		check_matches(char **mtch, t_ctx *res, int *i, char **text_paths);
t_vec2		set_player(t_map *map, char *mpos, t_vec2 *dir, t_vec2 *plane);
bool		free_parse(char *error, PEG *peg, char *fcontent, char **matches);

#endif
