/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_txtrs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 00:04:41 by lifranco          #+#    #+#             */
/*   Updated: 2026/09/24 04:52:46 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_txtr_width(t_ctx *ctx, t_cast *cst)
{
	if (cst->touched == NO)
		return (ctx->txtrs->no.w);
	else if (cst->touched == SO)
		return (ctx->txtrs->so.w);
	else if (cst->touched == EA)
		return (ctx->txtrs->ea.w);
	else if (cst->touched == WE)
		return (ctx->txtrs->we.w);
	return (0);
}

int	get_txtr_height(t_ctx *ctx, t_cast *cst)
{
	if (cst->touched == NO)
		return (ctx->txtrs->no.h);
	else if (cst->touched == SO)
		return (ctx->txtrs->so.h);
	else if (cst->touched == EA)
		return (ctx->txtrs->ea.h);
	else if (cst->touched == WE)
		return (ctx->txtrs->we.h);
	return (0);
}

t_img	get_txtr_image(t_ctx *ctx, t_cast *cst)
{
	if (cst->touched == NO)
		return (ctx->txtrs->no);
	else if (cst->touched == SO)
		return (ctx->txtrs->so);
	else if (cst->touched == EA)
		return (ctx->txtrs->ea);
	else if (cst->touched == WE)
		return (ctx->txtrs->we);
	return ((t_img){NULL, NULL, 0, 0});
}
