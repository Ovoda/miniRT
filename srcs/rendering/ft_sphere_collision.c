/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere_collision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 10:12:59 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/05 21:14:41 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int						ft_get_distance(t_delta delta,
		t_inter_point *inter_point)
{
	double t1;
	double t2;

	t1 = (-delta.b - sqrt(delta.delta)) / (2 * delta.a);
	t2 = (-delta.b + sqrt(delta.delta)) / (2 * delta.a);
	if (t2 < 0)
		return (0);
	inter_point->t = (t1 > 0 ? t1 : t2);
	return (1);
}

void					ft_get_normal(t_ray ray, t_vect obj_pos,
		t_inter_point *inter_point)
{
	ray.direction.x *= inter_point->t;
	ray.direction.y *= inter_point->t;
	ray.direction.z *= inter_point->t;
	inter_point->coord = add(ray.origin, ray.direction);
	inter_point->normal = normalize(sub(inter_point->coord, obj_pos));
}

inline t_inter_point	ft_sphere_collision(t_ray ray, t_vect pos,
		double diameter, int id)
{
	t_delta			delta;
	t_inter_point	inter_point;

	inter_point.type = SPHERE;
	inter_point.id = id;
	delta.a = pow(get_norm(ray.direction), 2);
	delta.b = 2 * dot(ray.direction, sub(ray.origin, pos));
	delta.c = pow(get_norm(sub(ray.origin, pos)), 2) - pow(diameter / 2, 2);
	delta.delta = pow(delta.b, 2) - 4 * delta.a * delta.c;
	inter_point.hit = FALSE;
	if (delta.delta < 0)
		return (inter_point);
	if (ft_get_distance(delta, &inter_point) == 0)
		return (inter_point);
	inter_point.hit = TRUE;
	ft_get_normal(ray, pos, &inter_point);
	if (dot(inter_point.normal, ray.direction) > 0)
		inter_point.normal = ft_scale(inter_point.normal, -1);
	return (inter_point);
}
