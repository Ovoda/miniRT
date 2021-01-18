/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder_collision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:51:23 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/05 12:50:12 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_inter_point	ft_find_edges(t_pack cylinder, t_ray ray,
		t_inter_point inter_point)
{
	double a;
	double max;

	ft_get_normal(ray, cylinder.pos, &inter_point);
	max = sqrt(pow(cylinder.height / 2.0, 2) + pow(cylinder.diameter / 2, 2));
	if (get_norm(sub(inter_point.coord, cylinder.pos)) > max)
	{
		inter_point.t = (inter_point.t2);
		ft_get_normal(ray, cylinder.pos, &inter_point);
	}
	if (get_norm(sub(inter_point.coord, cylinder.pos)) > max)
		return (inter_point);
	a = dot(cylinder.rot, sub(inter_point.coord, cylinder.pos));
	inter_point.normal = normalize(sub(inter_point.coord,
	add(cylinder.pos, ft_scale(cylinder.rot, a))));
	a = dot(ray.direction, inter_point.normal);
	if (a > 0)
		inter_point.normal = ft_scale(inter_point.normal, -1);
	inter_point.hit = TRUE;
	return (inter_point);
}

t_inter_point	ft_cylinder_collision(t_ray ray, t_pack cylinder, int id)
{
	t_inter_point	inter_point;
	t_delta			delta;
	t_ray			new_ray;
	t_vect			c_to_o;

	inter_point.hit = FALSE;
	inter_point.id = id;
	new_ray.origin = ray.origin;
	cylinder.rot = normalize(cylinder.rot);
	new_ray.direction = cross(ray.direction, cylinder.rot);
	c_to_o = sub(ray.origin, cylinder.pos);
	delta.a = dot(new_ray.direction, new_ray.direction);
	delta.b = 2 * dot(new_ray.direction, cross(c_to_o, cylinder.rot));
	delta.c = dot(cross(c_to_o, cylinder.rot),
		cross(c_to_o, cylinder.rot)) - pow(cylinder.diameter / 2, 2);
	delta.delta = pow(delta.b, 2) - 4 * delta.c * delta.a;
	if (delta.delta < 0)
		return (inter_point);
	inter_point.t1 = (-delta.b - sqrt(delta.delta)) / (2 * delta.a);
	inter_point.t2 = (-delta.b + sqrt(delta.delta)) / (2 * delta.a);
	if (inter_point.t2 < 0)
		return (inter_point);
	inter_point.t = (inter_point.t1 > 0 ? inter_point.t1 : inter_point.t2);
	return (ft_find_edges(cylinder, ray, inter_point));
}
