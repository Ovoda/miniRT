/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 14:09:28 by calide-n          #+#    #+#             */
/*   Updated: 2020/11/20 15:18:16 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>

typedef struct	s_options
{
	int		minus;
	int		zero;
	int		dot;
	int		star;
	int		width_on;
	int		width_value;
	int		precision;
	int		preci_star;
	char	type;
	int		nb_of_fill;
	char	fill_char;
	int		len;
}				t_options;

int				ft_manager(char const *input, va_list arg_list);
int				ft_printf(const char *input, ...);
int				ft_print_arg(t_options options, va_list arg_list);
int				ft_print_char(t_options option, int c);
int				ft_convert_s(t_options options, char *str);
int				ft_convert_p(t_options options, void *addr);
int				ft_convert_diux(t_options options, long nb);
int				ft_print(t_options options, char *str);
char			*ft_itoa_preci(long n, t_options options);
char			*ft_add_hexa_prefix(t_options *options, char *addr_str);
int				nbr_len(int n);
int				ft_is_type(char c);
t_options		ft_init_option();
char const		*ft_is_flag(char const *c, t_options *options);
void			ft_is_star(va_list arg_list, t_options *options, int p_or_w);
void			ft_is_dot(char const *ptr, t_options *options,
				va_list arg_list);
void			ft_get_options(char const *str, va_list arg_list,
				t_options *options);
void			ft_get_options_len(t_options *options, char **nbr, int nb);
int				ft_nbr_len_base(t_options options, long nb);
#endif
