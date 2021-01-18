/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 20:18:18 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/16 13:43:00 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_error(char *str)
{
	ft_printf("Error -> %s", str);
	exit(1);
}

int		ft_error_free(char *str, t_scene *scene)
{
	ft_free(scene);
	ft_printf("Error -> %s", str);
	exit(1);
}

int		ft_check_only_letter(char *line)
{
	int i;

	i = 0;
	ft_while_wspace(&line);
	while ((line[i] >= 'a' && line[i] <= 'z') ||
			(line[i] >= 'A' && line[i] <= 'Z'))
		i++;
	while (line[i])
	{
		if ((line[i] >= 'a' && line[i] <= 'z') ||
			(line[i] >= 'A' && line[i] <= 'Z'))
			ft_error("Why would you put letters here ??\n");
		i++;
	}
	return (1);
}

int		ft_check_rgb(int rgb)
{
	if ((rgb & 0xFF) > 255 || (rgb & 0xFF) < 0)
		return (0);
	if ((rgb >> 8 & 0xFF) > 255 || (rgb >> 8 & 0xFF) < 0)
		return (0);
	if ((rgb >> 16 & 0xFF) > 255 || (rgb >> 16 & 0xFF) < 0)
		return (0);
	return (1);
}

int		ft_check_params(t_scene scene)
{
	if (scene.render_y <= 0 || scene.render_x <= 0)
		return (0);
	if (scene.ambient_light_ratio < 0 || scene.ambient_light_rgb < 0)
		return (0);
	if (scene.ambient_light_ratio < 0.0 || scene.ambient_light_ratio > 1.0)
		return (0);
	if (scene.nb_of.cameras <= 0)
		return (0);
	return (1);
}
