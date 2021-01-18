/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:57:49 by calide-n          #+#    #+#             */
/*   Updated: 2020/11/19 20:26:02 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_add_hexa_prefix(t_options *options, char *addr_str)
{
	char *final_addr_str;

	if (!(final_addr_str = (char *)malloc(sizeof(char) *
					(ft_strlen(addr_str) + 3))))
		return (0);
	ft_bzero(final_addr_str, ft_strlen(addr_str) + 3);
	final_addr_str[0] = '0';
	if (options->type == 'p' || options->type == 'x')
		final_addr_str[1] = 'x';
	else
		final_addr_str[1] = 'X';
	ft_strlcat(final_addr_str, addr_str, ft_strlen(addr_str) + 3);
	if (options->precision == 0)
		options->precision = 2;
	return (final_addr_str);
}

int		ft_convert_p(t_options options, void *addr)
{
	char	*addr_str;
	long	addr_l;
	int		return_value;
	char	*final_str;

	addr_l = (long)addr;
	addr_str = ft_itoa_preci(addr_l, options);
	final_str = ft_add_hexa_prefix(&options, addr_str);
	if (!addr && options.precision == 2 && options.dot == 1)
		return_value = ft_convert_s(options, "0x");
	else
		return_value = ft_convert_s(options, final_str);
	free(addr_str);
	free(final_str);
	return (return_value);
}

int		ft_convert_s(t_options options, char *str)
{
	int	ret;
	int	to_free;

	to_free = 0;
	if (!str)
	{
		str = ft_strdup("(null)");
		to_free++;
	}
	if (options.type == 'p' && ft_strlen(str) > options.precision)
		options.len = ft_strlen(str);
	else
		options.len = options.precision;
	if (options.precision > ft_strlen(str) || options.dot == 0)
		options.len = ft_strlen(str);
	if (options.width_value > options.len)
		options.nb_of_fill = options.width_value - options.len;
	else
		options.nb_of_fill = 0;
	if (options.zero > 0 && options.precision >= 0)
		options.fill_char = '0';
	ret = ft_print(options, str);
	if (to_free == 1)
		free(str);
	return (ret);
}

int		ft_convert_diux(t_options options, long nb)
{
	char	*nbr;
	int		return_value;

	if (options.dot == 0 && options.width_value > 0 && options.zero == 1)
	{
		options.fill_char = '0';
		options.precision = options.width_value;
		if (nb < 0)
			options.precision--;
	}
	nbr = ft_itoa_preci(nb, options);
	ft_get_options_len(&options, &nbr, nb);
	if (options.width_value > ft_strlen(nbr))
		options.nb_of_fill = options.width_value - ft_strlen(nbr);
	return_value = ft_print(options, nbr);
	if (!(options.dot == 1 && options.precision == 0 && nb == 0))
		free(nbr);
	return (return_value);
}
