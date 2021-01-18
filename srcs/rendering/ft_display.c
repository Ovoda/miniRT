/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 18:26:44 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/16 14:28:54 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_exit(t_params *params)
{
	int i;

	i = 0;
	while (i < params->nb_cam)
	{
		mlx_destroy_image(params->env->mlx, params->env->img[i].addr);
		i++;
	}
	mlx_destroy_window(params->env->mlx, params->env->win);
	mlx_destroy_display(params->env->mlx);
	free(params->env->img);
	free(params->env->mlx);
	free(params);
	exit(0);
}

int	ft_img_to_window(int keycode, t_params *params)
{
	if (keycode == 32)
	{
		if (params->i >= params->nb_cam - 1)
			params->i = 0;
		else
			params->i += 1;
		ft_printf("\rYou're on camera %d", params->i);
		mlx_put_image_to_window(params->env->mlx, params->env->win,
				params->env->img[params->i].addr, 0, 0);
	}
	else if (keycode == 65307)
		ft_exit(params);
	return (0);
}

int	ft_put_img_back(t_params *params)
{
	mlx_put_image_to_window(params->env->mlx, params->env->win,
			params->env->img[params->i].addr, 0, 0);
	return (0);
}

int	ft_minimize(t_params *params)
{
	mlx_hook(params->env->win, 15, 1L << 16, ft_put_img_back, params);
	return (0);
}

int	ft_display(t_env *env, int nb_cam, t_scene *scene)
{
	static int	number = 0;
	t_params	*params;

	env->win = mlx_new_window(env->mlx, env->size_x, env->size_y, "miniRT");
	mlx_put_image_to_window(env->mlx, env->win, env->img[0].addr, 0, 0);
	ft_printf("All images are rendered\n");
	ft_printf("You can now press Space to switch between cameras\n");
	if (!(params = malloc(sizeof(t_params))))
		return (0);
	params->i = number;
	params->env = env;
	params->nb_cam = nb_cam;
	params->scene = scene;
	mlx_hook(env->win, 33, 1L << 5, ft_exit, params);
	mlx_hook(env->win, 2, 1L << 0, ft_img_to_window, params);
	mlx_hook(env->win, 15, 1L << 16, ft_minimize, params);
	return (0);
}
