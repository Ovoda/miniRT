/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_computing_01.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:12:13 by calide-n          #+#    #+#             */
/*   Updated: 2020/12/29 13:12:41 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vect	sub(t_vect a, t_vect b)
{
	t_vect vect;

	vect.x = a.x - b.x;
	vect.y = a.y - b.y;
	vect.z = a.z - b.z;
	return (vect);
}

t_vect	add(t_vect a, t_vect b)
{
	t_vect vect;

	vect.x = a.x + b.x;
	vect.y = a.y + b.y;
	vect.z = a.z + b.z;
	return (vect);
}

double	dot(t_vect a, t_vect b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vect	normalize(t_vect a)
{
	t_vect vect;
	double len;

	len = get_norm(a);
	vect.x = a.x / len;
	vect.y = a.y / len;
	vect.z = a.z / len;
	return (vect);
}

t_vect	vector(double x, double y, double z)
{
	t_vect vect;

	vect.x = x;
	vect.y = y;
	vect.z = z;
	return (vect);
}
