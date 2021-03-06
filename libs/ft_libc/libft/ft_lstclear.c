/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:56:41 by calide-n          #+#    #+#             */
/*   Updated: 2020/11/05 12:56:49 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *ptr;

	if (lst)
	{
		ptr = *lst;
		while (*lst)
		{
			ptr = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = ptr;
		}
	}
}
