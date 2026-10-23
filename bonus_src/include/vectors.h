/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:44:10 by lifranco          #+#    #+#             */
/*   Updated: 2026/10/20 10:32:51 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

typedef struct s_intvec
{
	int	x;
	int	y;
}	t_vec2i;

typedef struct s_floatvec
{
	double	x;
	double	y;
}	t_vec2;

t_vec2	vec2(double x, double y);

#endif
