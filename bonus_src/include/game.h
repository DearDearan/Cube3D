/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 16:13:31 by lifranco          #+#    #+#             */
/*   Updated: 2026/10/20 10:53:29 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

typedef struct s_context	t_ctx;
typedef struct s_castdata	t_cast;
typedef struct s_doors		t_door;

bool	load_imgs(t_ctx	*ctx, char **paths);
int		get_door(int x, int y, t_door *doors, int size);
void	upd_doors(t_ctx *ctx);
void	destroy_mlx(t_ctx *context);
bool	fill_ms_sfx(t_ctx *ctx, char **paths);

#endif
