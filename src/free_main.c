/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 03:12:23 by lifranco          #+#    #+#             */
/*   Updated: 2026/10/23 10:18:04 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_imgs(t_ctx *context)
{
	if (context->txtrs && context->txtrs->no.img)
		mlx_destroy_image(context->render->mlx, context->txtrs->no.img);
	if (context->txtrs && context->txtrs->so.img)
		mlx_destroy_image(context->render->mlx, context->txtrs->so.img);
	if (context->txtrs && context->txtrs->ea.img)
		mlx_destroy_image(context->render->mlx, context->txtrs->ea.img);
	if (context->txtrs && context->txtrs->we.img)
		mlx_destroy_image(context->render->mlx, context->txtrs->we.img);
	if (context->render->img)
		mlx_destroy_image(context->render->mlx, context->render->img);
	if (context->txtrs && context->txtrs->no.txtr)
		free(context->txtrs->no.txtr);
	if (context->txtrs && context->txtrs->so.txtr)
		free(context->txtrs->so.txtr);
	if (context->txtrs && context->txtrs->ea.txtr)
		free(context->txtrs->ea.txtr);
	if (context->txtrs && context->txtrs->we.txtr)
		free(context->txtrs->we.txtr);
}

void	destroy_mlx(t_ctx *context)
{
	free_imgs(context);
	if (context->render->win)
		mlx_destroy_window(context->render->mlx, context->render->win);
	if (context->render->mlx)
		mlx_destroy_context(context->render->mlx);
	if (context->txtrs)
		free(context->txtrs);
	if (context->map)
		free(context->map->map);
	if (context->render)
		free(context->render);
	free(context->map);
	ft_clear_filelist();
}
