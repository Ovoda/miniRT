/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 22:38:47 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/13 11:25:38 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_free_light_list(t_light_list *list)
{
	free(list->id);
	free(list->rgba);
	free(list->ratio);
	free(list->pos);
	free(list->dir);
	free(list->distance);
	return (1);
}

int		ft_free_camera_list(t_camera_list *list)
{
	free(list->id);
	free(list->fov);
	free(list->rot);
	free(list->pos);
	return (1);
}

int		ft_free_obj_list(t_obj_list *lst, int type)
{
	free(lst->id);
	free(lst->type);
	free(lst->rgba);
	if (type != 6)
		free(lst->pos);
	if (type != 2 && type != 6)
		free(lst->rot);
	if (type == 2 || type == 5)
		free(lst->diameter);
	if (type == 4 || type == 5)
		free(lst->height);
	if (type == 6)
	{
		free(lst->points[0]);
		free(lst->points[1]);
		free(lst->points[2]);
	}
	return (0);
}

void	ft_free(t_scene *scene)
{
	ft_free_light_list(&scene->lights);
	ft_free_camera_list(&scene->cameras);
	ft_free_obj_list(&scene->spheres, 2);
	ft_free_obj_list(&scene->planes, 3);
	ft_free_obj_list(&scene->squares, 4);
	ft_free_obj_list(&scene->cylinders, 5);
	ft_free_obj_list(&scene->triangles, 6);
}
