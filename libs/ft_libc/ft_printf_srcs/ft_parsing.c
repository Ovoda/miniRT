/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:09:43 by calide-n          #+#    #+#             */
/*   Updated: 2020/11/19 19:10:44 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_get_precision(char const *str)
{
	if ((*str < '0' || *str > '9') && *str != '*' && *str != '-')
		return (0);
	if ((*str >= '0' && *str <= '9') || *str == '-')
		return (ft_atoi(str));
	return (0);
}

char const	*ft_is_flag(char const *c, t_options *options)
{
	if (*c == '-' || *c == '0')
	{
		while (*c == '-')
		{
			options->minus++;
			c += 1;
		}
		while (*c == '0')
		{
			options->zero++;
			c += 1;
		}
		c -= 1;
		return (c);
	}
	return (c);
}

void		ft_is_star(va_list arg_list, t_options *options, int p_or_w)
{
	int	star_value;

	star_value = 0;
	star_value = va_arg(arg_list, int);
	if (star_value < 0)
	{
		star_value *= -1;
		if (p_or_w == 1)
			options->minus = 1;
		if (p_or_w == 0)
		{
			options->precision = -1;
			options->dot = 0;
		}
		else
			options->zero = 0;
	}
	else if (p_or_w == 0)
		options->precision = star_value;
	if (p_or_w == 1)
	{
		options->width_value = star_value;
		options->width_on = 1;
	}
}

void		ft_is_dot(char const *ptr, t_options *options, va_list arg_list)
{
	char const *tmp;

	options->dot = 1;
	while (*ptr == '.')
		ptr++;
	tmp = ptr;
	if (*tmp == '*')
	{
		options->preci_star = 1;
		ft_is_star(arg_list, options, 0);
		ptr += 1;
	}
	else
		options->precision = ft_get_precision(ptr);
	while (*ptr == '-' || (*ptr >= '0' && *ptr <= '9'))
		ptr += 1;
	options->type = *ptr;
	if (*ptr == '.')
		ft_is_dot(ptr, options, arg_list);
	return ;
}

void		ft_get_options(char const *str, va_list arg_list,
		t_options *options)
{
	char const *ptr;

	ptr = str;
	while (!ft_isalpha(*ptr) && *ptr != '%' && *ptr)
	{
		ptr = ft_is_flag(ptr, options);
		if (*ptr == '.')
		{
			ft_is_dot(ptr, options, arg_list);
			return ;
		}
		if (*ptr == '*')
			ft_is_star(arg_list, options, 1);
		if (*ptr >= '1' && *ptr <= '9')
		{
			options->width_on = 1;
			options->width_value = ft_atoi(ptr);
			ptr += nbr_len(options->width_value) - 1;
		}
		ptr += 1;
	}
	options->type = *ptr;
}
