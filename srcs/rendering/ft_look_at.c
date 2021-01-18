/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_look_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 11:29:59 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/10 11:10:38 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	ft_look_at(t_vect cam_dir)
{
	t_vect		wup;
	t_matrix	m;

	wup = vector(0, 1, 0);
	m.foward = cam_dir;
	if (cam_dir.y == 1)
		m.right = vector(-1, 0, 0);
	else if (cam_dir.y == -1)
		m.right = vector(1, 0, 0);
	else
		m.right = cross(wup, cam_dir);
	m.up = cross(m.foward, m.right);
	return (m);
}
