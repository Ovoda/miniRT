/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_computing_02.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:21:55 by calide-n          #+#    #+#             */
/*   Updated: 2020/12/29 13:14:17 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	get_norm(t_vect vect)
{
	return (sqrt(dot(vect, vect)));
}

t_vect	cross(t_vect a, t_vect b)
{
	t_vect vect;

	vect.x = (a.y * b.z) - (a.z * b.y);
	vect.y = (a.z * b.x) - (a.x * b.z);
	vect.z = (a.x * b.y) - (a.y * b.x);
	return (vect);
}

double	ft_max(double a, double b)
{
	return (a > b ? a : b);
}

double	ft_min(double a, double b)
{
	return (a < b ? a : b);
}

t_vect	ft_scale(t_vect a, double b)
{
	a.x *= b;
	a.y *= b;
	a.z *= b;
	return (a);
}
