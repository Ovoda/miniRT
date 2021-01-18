/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:11:40 by calide-n          #+#    #+#             */
/*   Updated: 2020/11/20 09:10:19 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_flag(t_options options, va_list arg_list, int *size)
{
	if (!ft_is_type(options.type))
		*size += ft_print_char(options, options.type);
	else if (options.type == 's'
			&& options.precision < 0 && options.preci_star == 0)
	{
		options.len = options.precision * -1;
		options.width_value = 0;
		*size += ft_convert_s(options, "");
	}
	else
		*size += ft_print_arg(options, arg_list);
}

int		ft_manager(char const *input, va_list arg_list)
{
	size_t		i;
	t_options	options;
	int			size;

	i = 0;
	size = 0;
	while (input[i])
	{
		if (input[i] == '%' && input[i + 1])
		{
			i++;
			options = ft_init_option();
			ft_get_options(&input[i], arg_list, &options);
			ft_print_flag(options, arg_list, &size);
			while (input[i] != options.type)
				i++;
		}
		else
		{
			ft_putchar_fd(input[i], 1);
			size++;
		}
		i++;
	}
	return (size);
}

int		ft_printf(const char *input, ...)
{
	va_list	arg_list;
	int		return_value;

	va_start(arg_list, input);
	return_value = ft_manager(input, arg_list);
	va_end(arg_list);
	return (return_value);
}
