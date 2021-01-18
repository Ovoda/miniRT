/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_obj_components.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 21:34:51 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/16 14:06:35 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_get_pos(char **line, t_obj *obj)
{
	ft_while_wspace(line);
	if (!ft_isnum_neg(line))
		return (0);
	if (obj->type != 6)
		return (ft_get_vect(line, 0, &obj->pos));
	return (1);
}

int		ft_get_rot(char **line, t_obj *obj)
{
	if (obj->type >= 3 && obj->type <= 5)
	{
		ft_while_wspace(line);
		if (!ft_isnum_neg(line))
			return (0);
		return (ft_get_vect(line, 1, &obj->rot));
	}
	return (1);
}

int		ft_get_diam(char **line, t_obj *obj)
{
	if (obj->type == 2 || obj->type == 5)
	{
		ft_while_wspace(line);
		if (!ft_isnum(line))
			return (0);
		obj->diameter = ft_atof(*line);
		ft_while_num(line);
		if (**line != '.')
			ft_while_num(line);
		if ((**line < 8 || **line > 14) && **line != 32)
			return (0);
		if (obj->diameter <= 0)
			return (0);
	}
	return (1);
}

int		ft_get_height(char **line, t_obj *obj)
{
	if (obj->type == 4 || obj->type == 5)
	{
		ft_while_wspace(line);
		if (!ft_isnum(line))
			return (0);
		obj->height = ft_atof(*line);
		ft_while_num(line);
		if (**line != '.')
			ft_while_num(line);
		if ((**line < 8 || **line > 14) && **line != 32)
			return (0);
		if (obj->height <= 0)
			return (0);
	}
	return (1);
}
