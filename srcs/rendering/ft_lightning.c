/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lightning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:09:24 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/05 15:58:29 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void				ft_pixel(t_img *img, int color, int index)
{
	img->buffer[index] = color & 0xFF;
	img->buffer[index + 1] = color >> 8 & 0xFF;
	img->buffer[index + 2] = color >> 16 & 0xFF;
	img->buffer[index + 3] = 0;
}

int					ft_add_lights(int final_color, int color)
{
	int r;
	int g;
	int b;

	if (final_color == 0)
		return (adjust_int(color));
	r = (final_color & 0xFF) + (color & 0xFF);
	g = (final_color >> 8 & 0xFF) + (color >> 8 & 0xFF);
	b = (final_color >> 16 & 0xFF) + (color >> 16 & 0xFF);
	final_color = r | g << 8 | b << 16;
	return (adjust_int(final_color));
}

t_color_coef		ft_light_hit(t_inter_point inter_point,
		t_scene scene, int i, t_color_coef color_coef)
{
	t_ray			ray_light;
	t_phong			phong;
	t_inter_point	inter_point_light;

	ray_light.origin = add(inter_point.coord,
			ft_scale(inter_point.normal, 0.001));
	ray_light.direction = normalize(sub(scene.lights.pos[i],
				inter_point.coord));
	inter_point_light = ft_objs_inter(scene, ray_light, inter_point.id);
	if (inter_point_light.hit == TRUE &&
			inter_point_light.t < scene.lights.distance[i])
		color_coef.is_in_shadow = TRUE;
	else
	{
		color_coef.is_in_shadow = FALSE;
		phong = ft_lightning(inter_point.ray, inter_point,
				scene.lights.pos[i]);
		ft_add_coef(&color_coef, scene.lights.ratio[i], scene.lights.rgba[i],
				phong);
	}
	return (color_coef);
}

t_color_coef		ft_init_coef(int color, double ratio)
{
	t_color_coef rgb;

	rgb.r = ratio * (color & 0xFF) / 255;
	rgb.g = ratio * (color >> 8 & 0xFF) / 255;
	rgb.b = ratio * (color >> 16 & 0xFF) / 255;
	return (rgb);
}

void				ft_render_pixel(t_scene scene, t_img *img,
		t_ray ray, int index)
{
	size_t			i;
	t_inter_point	inter_point;
	t_color_coef	color_coef;
	t_color_coef	tmp;

	i = -1;
	inter_point = ft_objs_inter(scene, ray, -1);
	inter_point.ray = ray;
	if (inter_point.hit == TRUE)
	{
		color_coef = ft_init_coef(inter_point.color, scene.ambient_light_ratio);
		while (++i < scene.nb_of.lights)
		{
			scene.lights.distance[i] = get_norm(sub(scene.lights.pos[i],
						inter_point.coord));
			scene.lights.dir[i] = (sub(scene.lights.pos[i],
						inter_point.coord));
			tmp = ft_light_hit(inter_point, scene, i, color_coef);
			if (tmp.is_in_shadow == FALSE)
				color_coef = ft_coef_p_coef(color_coef, tmp);
		}
		ft_pixel(img, ft_coef_x_color(color_coef, inter_point.color), index);
	}
	else
		ft_pixel(img, (10 | 10 << 8 | 10 << 16), index);
}
