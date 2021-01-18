/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:50:03 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/05 16:15:49 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_inter_point	ft_get_min(t_inter_point min, t_inter_point current,
				t_obj_list lst, int index)
{
	if (current.hit == TRUE)
	{
		if ((current.t < min.t || min.t == -1))
		{
			min = current;
			min.color = lst.rgba[index];
			min.id = lst.id[index];
		}
	}
	return (min);
}

t_inter_point	ft_manage_triangles(t_scene scene, t_ray ray, t_inter_point min)
{
	size_t			i;
	t_inter_point	current;

	i = -1;
	while (++i < scene.nb_of.triangles)
	{
		current = ft_triangle_collision(ray,
				scene.triangles.points[0][i],
				scene.triangles.points[1][i],
				scene.triangles.points[2][i]);
		min = ft_get_min(min, current, scene.triangles, i);
	}
	return (min);
}

t_inter_point	ft_manage_cylinders(t_scene scene, t_ray ray,
t_inter_point min, int current_id)
{
	size_t			i;
	t_inter_point	current;
	t_pack			pack;

	i = -1;
	(void)current_id;
	while (++i < scene.nb_of.cylinders)
	{
		if (scene.cylinders.id[i] != current_id)
		{
			pack.diameter = scene.cylinders.diameter[i];
			pack.height = scene.cylinders.height[i];
			pack.pos = scene.cylinders.pos[i];
			pack.rot = scene.cylinders.rot[i];
			current = ft_cylinder_collision(ray, pack, scene.cylinders.id[i]);
			min = ft_get_min(min, current, scene.cylinders, i);
		}
	}
	return (min);
}

t_inter_point	ft_objs_inter(t_scene scene, t_ray ray, int current_id)
{
	size_t			i;
	t_inter_point	min;

	min.t = -1;
	i = -1;
	min.hit = FALSE;
	while (++i < scene.nb_of.spheres)
		if (scene.spheres.id[i] != current_id)
		{
			min = ft_get_min(min, ft_sphere_collision(ray, scene.spheres.pos[i],
						scene.spheres.diameter[i], scene.spheres.id[i]),
						scene.spheres, i);
		}
	i = -1;
	while (++i < scene.nb_of.planes)
		min = ft_get_min(min, ft_plane_collision(ray, scene.planes.pos[i],
					scene.planes.rot[i]), scene.planes, i);
	i = -1;
	while (++i < scene.nb_of.squares)
		min = ft_get_min(min, ft_square_collision(ray, scene.squares.pos[i],
					scene.squares.rot[i], scene.squares.height[i]),
					scene.squares, i);
	min = ft_manage_triangles(scene, ray, min);
	min = ft_manage_cylinders(scene, ray, min, current_id);
	return (min);
}
