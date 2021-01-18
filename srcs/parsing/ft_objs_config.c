/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objs_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 19:38:21 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/16 14:22:20 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_push_to_array(t_obj_list *lst, t_obj obj, size_t *i)
{
	lst->type[*i] = obj.type;
	lst->id[*i] = obj.id;
	if (obj.type != 6)
		lst->pos[*i] = obj.pos;
	if (obj.type != 2 && obj.type != 6)
		lst->rot[*i] = obj.rot;
	if (obj.type == 2 || obj.type == 5)
		lst->diameter[*i] = obj.diameter;
	if (obj.type == 4 || obj.type == 5)
		lst->height[*i] = obj.height;
	lst->rgba[*i] = obj.rgba;
	if (obj.type == 6)
	{
		lst->points[0][*i] = obj.points[0];
		lst->points[1][*i] = obj.points[1];
		lst->points[2][*i] = obj.points[2];
	}
	*i += 1;
}

void	ft_push_to_scene(t_scene *scene, t_obj obj)
{
	static size_t spheres_index = 0;
	static size_t planes_index = 0;
	static size_t cylinders_index = 0;
	static size_t triangles_index = 0;
	static size_t squares_index = 0;

	if (obj.type == SPHERE)
		ft_push_to_array(&scene->spheres, obj, &spheres_index);
	if (obj.type == PLANE)
		ft_push_to_array(&scene->planes, obj, &planes_index);
	if (obj.type == SQUARE)
		ft_push_to_array(&scene->squares, obj, &squares_index);
	if (obj.type == CYLINDER)
		ft_push_to_array(&scene->cylinders, obj, &cylinders_index);
	if (obj.type == TRIANGLE)
		ft_push_to_array(&scene->triangles, obj, &triangles_index);
}

int		ft_check_letters(char **line)
{
	if (*line + 2)
		*line += 2;
	if (**line != 32 && (**line < 8 || **line > 14))
		return (0);
	while (**line == 32 || (**line >= 8 && **line <= 14))
		*line += 1;
	if (**line == 0)
		return (0);
	return (1);
}

int		ft_get_obj(char *line, t_scene *scene, int type, int id)
{
	t_obj	obj;

	if (!ft_check_letters(&line))
		return (0);
	obj.id = id;
	obj.type = type;
	if (type == 6)
	{
		if (!ft_get_vect(&line, 0, &obj.points[0]) || !ft_get_vect(&line,
		0, &obj.points[1]) || !ft_get_vect(&line, 0, &obj.points[2]))
			return (0);
	}
	else
	{
		if (!ft_get_pos(&line, &obj) || !ft_get_rot(&line, &obj) ||
			!ft_get_diam(&line, &obj) || !ft_get_height(&line, &obj))
			return (0);
	}
	while ((*line >= 8 && *line <= 14) || *line == 32)
		line++;
	obj.rgba = ft_get_rgba(&line);
	if (obj.rgba < 0)
		return (0);
	ft_push_to_scene(scene, obj);
	return (1);
}
