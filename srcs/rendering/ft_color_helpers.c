/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:26:13 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/05 13:28:21 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				adjust_int(int color)
{
	int r;
	int g;
	int b;

	r = color & 0xFF;
	g = color >> 8 & 0xFF;
	b = color >> 16 & 0xFF;
	r = r < 0 ? 0 : r;
	r = r > 255 ? 255 : r;
	g = g < 0 ? 0 : g;
	g = g > 255 ? 255 : g;
	b = b < 0 ? 0 : b;
	b = b > 255 ? 255 : b;
	color = r | g << 8 | b << 16;
	return (color);
}

void			adjust_array(double *rgb)
{
	rgb[0] = (rgb[0] < 0 ? 0 : rgb[0]);
	rgb[0] = (rgb[0] > 255 ? 255 : rgb[0]);
	rgb[1] = (rgb[1] < 0 ? 0 : rgb[1]);
	rgb[1] = (rgb[1] > 255 ? 255 : rgb[1]);
	rgb[2] = (rgb[2] < 0 ? 0 : rgb[2]);
	rgb[2] = (rgb[2] > 255 ? 255 : rgb[2]);
}

int				ft_coef_x_color(t_color_coef rgb, int color)
{
	int final_color;

	final_color = 0;
	rgb.r *= (color & 0xFF);
	rgb.g *= (color >> 8 & 0xFF);
	rgb.b *= (color >> 16 & 0xFF);
	rgb.r = (rgb.r < 0 ? 0 : rgb.r);
	rgb.r = (rgb.r > 255 ? 255 : rgb.r);
	rgb.g = (rgb.g < 0 ? 0 : rgb.g);
	rgb.g = (rgb.g > 255 ? 255 : rgb.g);
	rgb.b = (rgb.b < 0 ? 0 : rgb.b);
	rgb.b = (rgb.b > 255 ? 255 : rgb.b);
	final_color = (int)rgb.r | (int)rgb.g << 8 | (int)rgb.b << 16;
	return (final_color);
}

void			ft_add_coef(t_color_coef *rgb, double ratio,
				int color, t_phong phong)
{
	rgb->r = ratio * phong.diffuse * (color & 0xff) / 255 +
			phong.specular * (color & 0xff) / 255;
	rgb->g = ratio * phong.diffuse * (color >> 8 & 0xff) / 255 +
			phong.specular * (color >> 8 & 0xff) / 255;
	rgb->b = ratio * phong.diffuse * (color >> 16 & 0xff) / 255 +
			phong.specular * (color >> 16 & 0xff) / 255;
}

t_color_coef	ft_coef_p_coef(t_color_coef a, t_color_coef b)
{
	a.r += b.r;
	a.g += b.g;
	a.b += b.b;
	return (a);
}
