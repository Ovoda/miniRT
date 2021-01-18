/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_picker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:47:16 by calide-n          #+#    #+#             */
/*   Updated: 2020/11/19 21:18:32 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_arg(t_options options, va_list arg_list)
{
	(void)arg_list;
	(void)options;
	if (options.type == 'c')
		return (ft_print_char(options, va_arg(arg_list, int)));
	if (options.type == 's')
		return (ft_convert_s(options, va_arg(arg_list, char *)));
	if (options.type == 'p')
		return (ft_convert_p(options, va_arg(arg_list, void *)));
	if (options.type == 'd' || options.type == 'i')
		return (ft_convert_diux(options, va_arg(arg_list, int)));
	if (options.type == 'u')
		return (ft_convert_diux(options, va_arg(arg_list, unsigned int)));
	if (options.type == 'x' || options.type == 'X')
		return (ft_convert_diux(options, va_arg(arg_list, unsigned int)));
	if (options.type == '%')
		return (ft_print_char(options, '%'));
	return (0);
}
