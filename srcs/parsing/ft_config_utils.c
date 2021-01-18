/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 19:18:08 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/16 14:16:40 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_get_rgba(char **line)
{
	int r;
	int g;
	int b;
	int rgb;

	while ((**line >= 8 && **line <= 14) || **line == 32)
		*line += 1;
	if (!ft_isnum(line))
		return (-1);
	r = ft_atoi(*line);
	if (!ft_while_num(line) || !ft_iscomma_inc(line) || !ft_isnum(line))
		return (-1);
	g = ft_atoi(*line);
	if (!ft_while_num(line) || !ft_iscomma_inc(line) || !ft_isnum(line))
		return (-1);
	b = ft_atoi(*line);
	if (!ft_while_num(line) || (r > 255 || r < 0 || g > 255 ||
		g < 0 || b > 255 || b < 0))
		return (-1);
	rgb = r << 16 | g << 8 | b;
	while (**line == 32 || (**line >= 8 && **line <= 14))
		*line += 1;
	if (**line != 0)
		return (-1);
	return (rgb);
}

int		ft_get_vect(char **line, int is_unit, t_vect *a)
{
	while ((**line >= 8 && **line <= 14) || **line == 32)
		*line += 1;
	if (!ft_isnum_neg(line))
		return (0);
	a->x = ft_atof(*line);
	if (!ft_while_num_or_neg(line) ||
		!ft_iscomma_inc(line) || !ft_isnum_neg(line))
		return (0);
	a->y = ft_atof(*line);
	if (!ft_while_num_or_neg(line) ||
		!ft_iscomma_inc(line) || !ft_isnum_neg(line))
		return (0);
	a->z = ft_atof(*line);
	ft_while_num_or_neg(line);
	if (is_unit == 1 && (a->x < -1.0 || a->x > 1.0 ||
				a->y < -1.0 || a->y > 1.0 ||
				a->z < -1.0 || a->z > 1.0))
		return (0);
	return (1);
}

int		ft_atoi_error(char **str, int *nb)
{
	int i;
	int sign;

	i = 0;
	*nb = 0;
	sign = 1;
	while ((**str >= 8 && **str <= 14) || **str == 32)
		*str += 1;
	if (**str == '-')
	{
		sign = -1;
		*str += 1;
	}
	while (**str)
	{
		if (**str >= '0' && **str <= '9')
			*nb = *nb * 10 + **str - 48;
		else if ((**str >= 8 && **str <= 14) || **str == 32)
			break ;
		else
			return (0);
		*str += 1;
	}
	*nb *= sign;
	return (1);
}
