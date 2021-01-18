/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:47:41 by calide-n          #+#    #+#             */
/*   Updated: 2020/11/05 12:48:07 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*dst;
	unsigned int	i;

	if (!(dst = (char *)malloc(count * size)))
		return (NULL);
	i = 0;
	while (i < (count * size))
	{
		dst[i] = 0;
		i++;
	}
	return ((void *)dst);
}
