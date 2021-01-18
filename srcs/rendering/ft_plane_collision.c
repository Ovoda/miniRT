/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 10:12:59 by calide-n          #+#    #+#             */
/*   Updated: 2020/12/20 20:53:00 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

inline t_inter_point	ft_plane_collision(t_ray ray, t_vect point,
										t_vect normal)
{
	t_inter_point	inter_point;
	double			a;
	double			b;

	inter_point.type = PLANE;
	inter_point.hit = FALSE;
	a = dot(sub(ray.origin, point), normal);
	b = dot(ray.direction, normal);
	inter_point.t = -a / b;
	if (inter_point.t >= 0)
	{
		ray.direction.x *= inter_point.t;
		ray.direction.y *= inter_point.t;
		ray.direction.z *= inter_point.t;
		inter_point.coord = add(ray.origin, ray.direction);
		if (b > 0)
			normal = ft_scale(normal, -1);
		inter_point.normal = normalize(normal);
		inter_point.hit = TRUE;
	}
	return (inter_point);
}
