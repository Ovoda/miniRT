/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:11:10 by calide-n          #+#    #+#             */
/*   Updated: 2020/11/19 21:12:03 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(t_options option, int c)
{
	int		size;
	char	fill;

	size = 1;
	fill = ' ';
	if (c == '%' && option.zero == 1 && option.minus == 0)
		fill = '0';
	if (option.minus == 0)
		while (option.width_value - 1 > 0)
		{
			ft_putchar_fd(fill, 1);
			option.width_value--;
			size++;
		}
	ft_putchar_fd(c, 1);
	if (option.minus == 1)
		while (option.width_value - 1 > 0)
		{
			ft_putchar_fd(fill, 1);
			option.width_value--;
			size++;
		}
	return (size);
}

int	ft_print_filling_char(int i, char c)
{
	int len;

	len = 0;
	while (i > 0)
	{
		write(1, &c, 1);
		i--;
		len++;
	}
	return (len);
}

int	ft_print(t_options options, char *str)
{
	int len;

	len = 0;
	if (options.minus == 0)
		len += ft_print_filling_char(options.nb_of_fill, options.fill_char);
	len += write(1, str, options.len);
	if (options.minus >= 1)
		len += ft_print_filling_char(options.nb_of_fill, options.fill_char);
	return (len);
}
