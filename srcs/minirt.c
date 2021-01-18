/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 12:46:46 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/16 14:28:34 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_setup_env(t_scene *scene, t_env *env, int save)
{
	int	x;
	int	y;

	env->mlx = mlx_init();
	if (save != 0)
	{
		mlx_get_screen_size(env->mlx, &x, &y);
		env->size_x = (scene->render_x > x ? x : scene->render_x);
		env->size_y = (scene->render_y > y ? y : scene->render_y);
	}
	else
	{
		env->size_x = scene->render_x;
		env->size_y = scene->render_y;
	}
	scene->render_x = env->size_x;
	scene->render_y = env->size_y;
	scene->aspect_ratio = (double)scene->render_x / (double)scene->render_y;
	if (!(env->img = malloc(sizeof(t_img) * scene->nb_of.cameras)))
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_scene	scene;
	t_env	env;
	int		save;

	ft_init_scene(&scene);
	ft_printf("\033[1mParsing...			");
	save = 1;
	if (argv[2])
		save = ft_strcmp(argv[2], "--save");
	if (argc == 2 || (argc == 3 && save == 0))
		ft_parser(argv[1], &scene);
	else
		ft_error("Input error\n");
	if (!ft_check_params(scene))
		ft_error_free("Please check your params\n", &scene);
	ft_setup_env(&scene, &env, save);
	ft_printf("\033[1;32mDone\033[0m\033[1m\n");
	ft_printf("I'm ready to render %d image(s)\n", scene.nb_of.cameras);
	ft_render(scene, &env);
	ft_save(argc, argv, &scene, &env);
	ft_display(&env, scene.nb_of.cameras, &scene);
	ft_free(&scene);
	mlx_loop(env.mlx);
	return (0);
}
