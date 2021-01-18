/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:13:11 by calide-n          #+#    #+#             */
/*   Updated: 2020/11/19 18:59:44 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			nbr_len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int			ft_nbr_len_base(t_options options, long nb)
{
	int	divider;
	int	size;

	if (options.type == 'd' || options.type == 'i' || options.type == 'u')
		divider = 10;
	if (options.type == 'X' || options.type == 'x' || options.type == 'p')
		divider = 16;
	size = 0;
	if (nb <= 0)
		size++;
	while (nb)
	{
		nb /= divider;
		size++;
	}
	return (size);
}

int			ft_is_type(char c)
{
	return ((c == 'c') ||
			(c == 's') ||
			(c == 'p') ||
			(c == 'd') ||
			(c == 'i') ||
			(c == 'u') ||
			(c == 'x') ||
			(c == 'X') ||
			(c == '%'));
}

t_options	ft_init_option(void)
{
	t_options options;

	options.minus = 0;
	options.zero = 0;
	options.dot = 0;
	options.precision = 0;
	options.preci_star = 0;
	options.star = 0;
	options.width_on = 0;
	options.width_value = 0;
	options.nb_of_fill = 0;
	options.fill_char = ' ';
	options.len = 0;
	return (options);
}
