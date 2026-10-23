/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 03:05:24 by lifranco          #+#    #+#             */
/*   Updated: 2026/08/31 04:06:56 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

void	key_down_hook(int key, void *param);
void	key_up_hook(int key, void *param);
void	key_held(t_ctx *ctx);

#endif
