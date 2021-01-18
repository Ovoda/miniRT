/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:46:05 by calide-n          #+#    #+#             */
/*   Updated: 2020/11/19 16:10:18 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char const *str)
{
	int				i;
	long long int	sign;
	long long int	nb;

	nb = 0;
	i = 0;
	sign = 1;
	while (((str[i] > 8 && str[i] < 14) || str[i] == 32))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		sign = (str[i] == '-' ? -1 : sign);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + ((long long int)str[i] - 48);
		if (nb > 2147483648 && sign == 1)
			return (-1);
		if (nb > 2147483648 && sign == -1)
			return (0);
		i++;
	}
	return (nb * sign);
}
