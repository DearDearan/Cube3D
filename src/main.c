/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 17:06:52 by lifranco          #+#    #+#             */
/*   Updated: 2026/10/23 10:18:55 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	the_game(void *ctx)
{
	t_ctx	*new;

	new = (t_ctx *) ctx;
	key_held(new);
	mlx_clear_window(new->render->mlx,
		new->render->win, (mlx_color){.rgba = 0x000000FF});
	render(new, new->render);
}

void	win_hook(int event, void *param)
{
	if (event == 0)
		mlx_loop_end((mlx_context)param);
}

static bool	init_game(t_ctx *context, mlx_window_create_info *info)
{
	context->render = ft_calloc(1, sizeof(t_draw));
	context->map = ft_calloc(1, sizeof(t_map));
	context->txtrs = NULL;
	ft_bzero(&context->held, sizeof(t_key));
	if (!context->render || !context->map)
	{
		printf("Error: Malloc Error\n");
		return (false);
	}
	context->render->mlx = mlx_init();
	if (!context->render->mlx)
	{
		ft_dprintf(2, "Error: MLX INIT\n");
		return (false);
	}
	context->render->img = mlx_new_image(context->render->mlx, WIDTH, HEIGHT);
	info->title = "スリーディーロンパ";
	info->width = WIDTH;
	info->height = HEIGHT;
	mlx_set_fps_goal(context->render->mlx, 120);
	context->render->win = mlx_new_window(context->render->mlx, info);
	return (true);
}

int	main(int argc, char **argv)
{
	mlx_window_create_info	info;
	t_ctx					context;

	if (argc != 2)
	{
		printf("Error: Need 2 Arguments, received %d.\n", argc);
		printf("USAGE: ./cub3d [MAP]\n");
		return (1);
	}
	info = (mlx_window_create_info){0};
	if (!init_game(&context, &info) || !parse_map(argv[1], &context))
	{
		destroy_mlx(&context);
		return (1);
	}
	mlx_on_event(context.render->mlx, context.render->win,
		MLX_WINDOW_EVENT, win_hook, context.render->mlx);
	mlx_on_event(context.render->mlx, context.render->win,
		MLX_KEYDOWN, key_down_hook, &context);
	mlx_on_event(context.render->mlx, context.render->win,
		MLX_KEYUP, key_up_hook, &context);
	mlx_add_loop_hook(context.render->mlx, the_game, &context);
	mlx_loop(context.render->mlx);
	destroy_mlx(&context);
	return (0);
}
