/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:59:44 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/16 14:25:48 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_parse_line(char *line, t_scene *scene)
{
	static int	id = 0;

	id++;
	if (ft_has_obj_letter(line, "R"))
		return (ft_get_resolution(&line, scene));
	else if (ft_has_obj_letter(line, "A"))
		return (ft_get_ambient_light(line, scene));
	else if (ft_has_obj_letter(line, "c"))
		return (ft_get_camera(line, scene));
	else if (ft_has_obj_letter(line, "l"))
		return (ft_get_light(line, scene));
	else if (ft_has_obj_letter(line, "sp"))
		return (ft_get_obj(line, scene, 2, id));
	else if (ft_has_obj_letter(line, "pl"))
		return (ft_get_obj(line, scene, 3, id));
	else if (ft_has_obj_letter(line, "sq"))
		return (ft_get_obj(line, scene, 4, id));
	else if (ft_has_obj_letter(line, "cy"))
		return (ft_get_obj(line, scene, 5, id));
	else if (ft_has_obj_letter(line, "tr"))
		return (ft_get_obj(line, scene, 6, id));
	return (ft_parse_line_ret(line));
}

int		ft_init_obj_list(t_obj_list *lst, int n, int type)
{
	if (!(lst->id = malloc(sizeof(int) * n)) ||
			!(lst->type = malloc(sizeof(int) * n)))
		return (0);
	if (type != 6)
		if (!(lst->pos = malloc(sizeof(t_vect) * n)))
			return (0);
	if (type != 2 && type != 6)
		if (!(lst->rot = malloc(sizeof(t_vect) * n)))
			return (0);
	if (type == 2 || type == 5)
		if (!(lst->diameter = malloc(sizeof(double) * n)))
			return (0);
	if (type == 4 || type == 5)
		if (!(lst->height = malloc(sizeof(double) * n)))
			return (0);
	if (type == 6)
	{
		lst->points[0] = malloc(sizeof(t_vect) * n);
		lst->points[1] = malloc(sizeof(t_vect) * n);
		lst->points[2] = malloc(sizeof(t_vect) * n);
		if (lst->points[0] == NULL || lst->points[1] == NULL ||
				lst->points[2] == NULL)
			return (0);
	}
	return ((lst->rgba = malloc(sizeof(int) * n)) == NULL ? 0 : 1);
}

int		ft_init_cam_list(t_camera_list *list, int n)
{
	if (!(list->id = malloc(sizeof(int) * n)))
		return (0);
	if (!(list->fov = malloc(sizeof(double) * n)))
		return (0);
	if (!(list->rot = malloc(sizeof(t_vect) * n)))
		return (0);
	if (!(list->pos = malloc(sizeof(t_vect) * n)))
		return (0);
	return (1);
}

int		ft_init_light_list(t_light_list *list, int n)
{
	if (!(list->id = malloc(sizeof(int) * n)))
		return (0);
	if (!(list->rgba = malloc(sizeof(int) * n)))
		return (0);
	if (!(list->ratio = malloc(sizeof(double) * n)))
		return (0);
	if (!(list->pos = malloc(sizeof(t_vect) * n)))
		return (0);
	if (!(list->dir = malloc(sizeof(t_vect) * n)))
		return (0);
	if (!(list->distance = malloc(sizeof(double) * n)))
		return (0);
	return (1);
}

int		ft_init_scene_list(t_scene *scene)
{
	(void)scene;
	if (!ft_init_light_list(&scene->lights, scene->nb_of.lights))
		ft_printf("light pb\n");
	if (!ft_init_cam_list(&scene->cameras, scene->nb_of.cameras))
		ft_printf("cam pb\n");
	if (!ft_init_obj_list(&scene->spheres, scene->nb_of.spheres, 2))
		ft_printf("sphere pb\n");
	if (!ft_init_obj_list(&scene->planes, scene->nb_of.planes, 3))
		ft_printf("planes pb\n");
	if (!ft_init_obj_list(&scene->squares, scene->nb_of.squares, 4))
		ft_printf("square pb\n");
	if (!ft_init_obj_list(&scene->cylinders, scene->nb_of.cylinders, 5))
		ft_printf("cy pb\n");
	if (!ft_init_obj_list(&scene->triangles, scene->nb_of.triangles, 6))
		ft_printf("tr pb\n");
	return (1);
}
