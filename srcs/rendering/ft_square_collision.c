/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square_collision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 14:12:12 by calide-n          #+#    #+#             */
/*   Updated: 2020/12/20 18:42:00 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_inter_point	ft_square_collision(t_ray ray, t_vect pos,
				t_vect rot, double height)
{
	t_inter_point	inter_point;
	t_vect			ab;

	inter_point = ft_plane_collision(ray, pos, rot);
	height /= 2;
	if (inter_point.hit == TRUE)
	{
		inter_point.hit = FALSE;
		ab = sub(inter_point.coord, pos);
		if (fabs(ab.x) <= height &&
				fabs(ab.y) <= height &&
				fabs(ab.z) <= height)
			inter_point.hit = TRUE;
	}
	return (inter_point);
}
