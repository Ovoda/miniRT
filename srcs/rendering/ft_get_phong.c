/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_phong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 20:43:23 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/05 21:13:14 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_phong	ft_lightning(t_ray ray, t_inter_point inter_point,
		t_vect light_pos)
{
	t_vect	h;
	t_vect	viewer_direction;
	t_phong	phong;
	t_vect	light_direction;
	double	prod;

	viewer_direction.x = 0;
	viewer_direction.y = 0;
	viewer_direction.z = 0;
	light_direction.x = 0;
	light_direction.y = 0;
	light_direction.z = 0;
	phong.diffuse = 0;
	phong.specular = 0;
	light_direction = normalize(sub(light_pos, inter_point.coord));
	phong.diffuse = dot(inter_point.normal, light_direction);
	phong.diffuse = (phong.diffuse < 0 ? 0 : phong.diffuse);
	viewer_direction = ft_scale(ray.direction, -1);
	h = sub(ft_scale(inter_point.normal,
	(2 * dot(inter_point.normal, (light_direction)))), (light_direction));
	prod = dot(h, viewer_direction) / get_norm(viewer_direction) *
		get_norm(viewer_direction);
	if (dot(h, viewer_direction) > 0)
		phong.specular = pow(prod, SPEC);
	return (phong);
}
