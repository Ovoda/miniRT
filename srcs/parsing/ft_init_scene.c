/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:32:17 by calide-n          #+#    #+#             */
/*   Updated: 2020/12/28 19:49:01 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_init_scene(t_scene *scene)
{
	scene->render_x = 0;
	scene->render_y = 0;
	scene->ambient_light_ratio = -1;
	scene->ambient_light_rgb = -1;
	scene->nb_of.cameras = 0;
	scene->nb_of.lights = 0;
	scene->nb_of.spheres = 0;
	scene->nb_of.cylinders = 0;
	scene->nb_of.planes = 0;
	scene->nb_of.triangles = 0;
	scene->nb_of.squares = 0;
}
