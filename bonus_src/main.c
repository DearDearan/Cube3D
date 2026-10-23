/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 17:06:52 by lifranco          #+#    #+#             */
/*   Updated: 2026/10/23 10:20:19 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	the_game(void *ctx)
{
	t_ctx	*new;

	new = (t_ctx *) ctx;
	key_held(new);
	upd_doors(new);
	if (new->frame % 10 == 0 && new->focus)
		mlx_mouse_move(new->render->mlx,
			new->render->win, WIDTH / 2, HEIGHT / 2);
	mlx_clear_window(new->render->mlx, new->render->win,
		(mlx_color){.rgba = 0x000000FF});
	render(new, new->render);
	new->frame++;
}

static void	win_hook(int event, void *param)
{
	t_ctx	*ctx;

	ctx = (t_ctx *) param;
	if (event == MLX_WINDOW_CLOSE)
		mlx_loop_end(ctx->render->mlx);
	if (event == MLX_WINDOW_UNFOCUS)
	{
		mlx_mouse_show(ctx->render->mlx);
		ctx->focus = false;
	}
	else if (event == MLX_WINDOW_FOCUS)
	{
		mlx_mouse_hide(ctx->render->mlx);
		mlx_mouse_move(ctx->render->mlx,
			ctx->render->win, WIDTH / 2, HEIGHT / 2);
		ctx->focus = true;
	}
}

static bool	init_game(t_ctx *context, mlx_window_create_info *info)
{
	struct timeval	t;

	context->render = ft_calloc(1, sizeof(t_draw));
	context->sprite = ft_calloc(1, sizeof(t_ctx));
	context->txtrs = ft_calloc(6, sizeof(t_img));
	if (!context->render || !context->sprite || !context->txtrs)
	{
		printf("Error: Malloc Error\n");
		return (false);
	}
	context->render->mlx = mlx_init();
	if (!context->render->mlx)
	{
		ft_dprintf(2, "Error: MLX INIT FAIL\n");
		return (false);
	}
	context->render->img = mlx_new_image(context->render->mlx, WIDTH, HEIGHT);
	info->title = "スリーディーロンパ";
	info->width = WIDTH;
	info->height = HEIGHT;
	context->render->win = mlx_new_window(context->render->mlx, info);
	gettimeofday(&t, NULL);
	srand(t.tv_usec);
	return (true);
}

static void	set_game(t_ctx *ctx)
{
	mlx_on_event(ctx->render->mlx, ctx->render->win,
		MLX_WINDOW_EVENT, win_hook, ctx);
	mlx_on_event(ctx->render->mlx, ctx->render->win,
		MLX_KEYDOWN, key_down_hook, ctx);
	mlx_on_event(ctx->render->mlx, ctx->render->win,
		MLX_KEYUP, key_up_hook, ctx);
	mlx_mouse_hide(ctx->render->mlx);
	mlx_mouse_move(ctx->render->mlx,
		ctx->render->win, WIDTH / 2, HEIGHT / 2);
	mlx_set_channel_volume(ctx->render->mlx, ctx->snds.ch_music,
		0.3, 0.3);
	mlx_set_channel_volume(ctx->render->mlx, ctx->snds.ch_sfx[0],
		0.8, 0.8);
	mlx_set_channel_volume(ctx->render->mlx, ctx->snds.ch_sfx[1],
		0.8, 0.8);
	mlx_play_sound_ex(ctx->render->mlx, ctx->snds.ch_music,
		ctx->snds.snd_msc, 0, -0.0, true);
	mlx_add_loop_hook(ctx->render->mlx, the_game, ctx);
	mlx_set_fps_goal(ctx->render->mlx, 120);
}

int	main(int argc, char **argv)
{
	mlx_window_create_info	info;
	t_ctx					context;

	if (argc != 2)
	{
		printf("Error: Need 1 Argument, received %d.\n", argc - 1);
		printf("USAGE: ./cub3d [MAP]\n");
		return (1);
	}
	info = (mlx_window_create_info){0};
	ft_bzero(&context, sizeof(context));
	if (!init_game(&context, &info) || !parse_map(argv[1], &context))
	{
		destroy_mlx(&context);
		return (1);
	}
	set_game(&context);
	mlx_loop(context.render->mlx);
	destroy_mlx(&context);
	return (0);
}
