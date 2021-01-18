/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:53:28 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/16 14:23:25 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_get_resolution(char **line, t_scene *scene)
{
	if (scene->render_x != 0 && scene->render_y != 0)
		return (0);
	*line += 1;
	if (!ft_atoi_error(line, &scene->render_x) ||
			!ft_atoi_error(line, &scene->render_y))
		return (0);
	while (**line)
	{
		if ((**line < 8 || **line > 14) && **line != 32)
			return (0);
		*line += 1;
	}
	scene->aspect_ratio = (double)scene->render_x / (double)scene->render_y;
	return (1);
}

int		ft_get_ambient_light(char *line, t_scene *scene)
{
	line++;
	if (scene->ambient_light_ratio != -1 && scene->ambient_light_rgb != -1)
		return (0);
	while ((*line >= 8 && *line <= 14) || *line == 32)
		line++;
	if (!ft_isnum(&line))
		return (0);
	scene->ambient_light_ratio = ft_atof(line);
	while ((*line >= '0' && *line <= '9') || *line == '.')
		line++;
	ft_while_wspace(&line);
	if (!ft_isnum(&line))
		return (0);
	scene->ambient_light_rgb = ft_get_rgba(&line);
	if (scene->ambient_light_rgb < 0)
		return (0);
	return (1);
}

int		ft_get_light(char *line, t_scene *scene)
{
	static size_t	index = 0;

	line++;
	if (!ft_get_vect(&line, 0, &scene->lights.pos[index]))
		return (0);
	ft_while_wspace(&line);
	if (!ft_isnum_neg(&line))
		return (0);
	scene->lights.ratio[index] = ft_atof(line);
	if (scene->lights.ratio[index] <= 0 || scene->lights.ratio[index] > 1.0)
		return (0);
	ft_while_num(&line);
	if (*line == '.')
		line++;
	ft_while_num(&line);
	scene->lights.rgba[index] = ft_get_rgba(&line);
	if (scene->lights.rgba[index] < 0)
		return (0);
	index++;
	return (1);
}

int		ft_get_camera(char *line, t_scene *scene)
{
	static size_t	index = 0;
	double			fov;

	line++;
	if (!ft_get_vect(&line, 0, &scene->cameras.pos[index]) ||
		!ft_get_vect(&line, 1, &scene->cameras.rot[index]))
		return (0);
	ft_while_wspace(&line);
	if (!ft_isnum(&line))
		return (0);
	fov = ft_atof(line);
	scene->cameras.fov[index] = fov * M_PI / 180;
	ft_while_num(&line);
	if (*line == '.')
		line++;
	ft_while_num(&line);
	if (scene->cameras.fov[index] <= 0 || scene->cameras.fov[index] > M_PI)
		return (0);
	while (*line == 32 || (*line >= 8 && *line <= 14))
		line++;
	if (*line != 0)
		return (0);
	index++;
	return (1);
}
