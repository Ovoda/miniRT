/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:09:50 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/15 11:47:47 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_get_nbr_len(int n)
{
	size_t len;

	len = 0;
	if (n <= 0)
		len++;
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int		ft_is_white_space(char c)
{
	return ((c > 8 && c < 14) || c == 32);
}

void	ft_while_not_num(char **line)
{
	while (ft_is_white_space(**line))
		*line += 1;
}

void	ft_while_not_wspace(char **line)
{
	while (!ft_is_white_space(**line))
		*line += 1;
}

double	ft_atof(char *str)
{
	double f;
	double sign;
	double divider;
	size_t i;

	divider = 0.1;
	f = 0;
	sign = 1;
	i = -1;
	while (str[i] < '0' || str[i] > '9')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		f = f * 10 + str[i++] - 48;
	}
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		f = f + (str[i] - 48) * divider;
		divider /= 10;
		i++;
	}
	return (f * sign);
}
