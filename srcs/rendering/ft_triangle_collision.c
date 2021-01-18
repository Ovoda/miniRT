/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triangle_collision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:03:22 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/05 13:28:52 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				ft_check_edge(t_vect p, t_vect a, t_vect b, t_vect normal)
{
	t_vect	ap;
	t_vect	ab;
	t_vect	c;

	ap = sub(p, a);
	ab = sub(b, a);
	c = cross(ab, ap);
	if (dot(normal, c) < 0)
		return (0);
	return (1);
}

t_inter_point	ft_triangle_collision(t_ray ray, t_vect a, t_vect b, t_vect c)
{
	t_vect			ab;
	t_vect			ac;
	t_vect			normal;
	t_inter_point	inter_point;

	ab = sub(b, a);
	ac = sub(c, a);
	normal = normalize(cross(ab, ac));
	inter_point = ft_plane_collision(ray, b, normal);
	if (inter_point.hit == TRUE)
	{
		if (!ft_check_edge(inter_point.coord, a, b, normal) ||
				!ft_check_edge(inter_point.coord, b, c, normal) ||
				!ft_check_edge(inter_point.coord, c, a, normal))
		{
			inter_point.hit = FALSE;
			return (inter_point);
		}
	}
	return (inter_point);
}
