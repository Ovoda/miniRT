/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:14:24 by calide-n          #+#    #+#             */
/*   Updated: 2020/11/19 19:15:11 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_create_nbr(t_options *options, int size, long n)
{
	char	*nbr;
	int		malloc_size;

	if (options->dot == 0 && options->zero == 1)
		options->precision = options->width_value;
	if (options->precision > size)
	{
		malloc_size = options->precision + 1;
		options->precision = options->precision - size;
	}
	else
	{
		options->precision = 0;
		malloc_size = size + 1;
	}
	if (!(nbr = malloc(sizeof(char) * (malloc_size))))
		return (0);
	ft_bzero(nbr, malloc_size);
	if (options->type != 'p' && n < 0)
		nbr[0] = '-';
	return (nbr);
}

char	ft_fill_nbr(t_options options, unsigned long *nb)
{
	char		c;
	static char	base_lowercase[] = "0123456789abcdef";
	static char	base_uppercase[] = "0123456789ABCDEF";

	if (options.type == 'u' || options.type == 'd' || options.type == 'i')
	{
		c = *nb % 10 + 48;
		*nb /= 10;
	}
	if (options.type == 'x' || options.type == 'X' || options.type == 'p')
	{
		if (options.type == 'x' || options.type == 'p')
			c = base_lowercase[*nb % 16];
		else
			c = base_uppercase[*nb % 16];
		*nb /= 16;
	}
	return (c);
}

char	*ft_init_itoa(long n, t_options options, int *size, int *i_stop)
{
	int				i;
	char			*nbr;

	i = 0;
	if (n < 0)
	{
		options.precision++;
		*i_stop = 1;
		i = 1;
		*size += 1;
	}
	nbr = ft_create_nbr(&options, *size, n);
	while (options.precision > 0)
	{
		nbr[i] = '0';
		i++;
		*size += 1;
		options.precision--;
	}
	return (nbr);
}

char	*ft_itoa_preci(long n, t_options options)
{
	char			*nbr;
	unsigned long	nb;
	int				size;
	int				i_stop;

	nb = n;
	if (n < 0)
		nb = -n;
	i_stop = 0;
	size = ft_nbr_len_base(options, nb);
	nbr = ft_init_itoa(n, options, &size, &i_stop);
	nbr[size] = '\0';
	size--;
	while (size >= i_stop)
	{
		nbr[size] = ft_fill_nbr(options, &nb);
		size--;
	}
	return (nbr);
}

void	ft_get_options_len(t_options *options, char **nbr, int nb)
{
	if (options->dot == 1 && options->precision == 0 && nb == 0)
	{
		options->len = 0;
		free(*nbr);
		*nbr = "";
	}
	else
		options->len = ft_strlen(*nbr);
	if (options->precision < 0 && options->preci_star == 0)
	{
		options->minus = 1;
		options->nb_of_fill = options->precision * -1 - options->len;
		options->width_value = 0;
	}
}
