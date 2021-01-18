/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:57:27 by calide-n          #+#    #+#             */
/*   Updated: 2020/11/05 12:57:41 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *begin;
	t_list *new;
	t_list *tmp;

	if (lst)
	{
		tmp = lst;
		if (!(begin = ft_lstnew(f(tmp->content))))
			return (0);
		tmp = tmp->next;
		while (tmp)
		{
			if (!(new = ft_lstnew(f(tmp->content))))
			{
				ft_lstclear(&begin, del);
				return (0);
			}
			ft_lstadd_back(&begin, new);
			tmp = tmp->next;
		}
		return (begin);
	}
	return (NULL);
}
