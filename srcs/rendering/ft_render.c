/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:51:44 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/12 08:57:44 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vect	get_pixel_pos(t_scene scene, int x, int y, t_camera camera)
{
	t_vect pixel;
	double scale;
	t_vect tmp;
	t_vect rot_vect[3];

	scale = tan(camera.fov / 2);
	pixel.x = (2 * (x + 0.5) / (double)scene.render_x - 1)
		* scene.aspect_ratio * scale;
	pixel.y = (1 - 2 * (y + 0.5) / (double)scene.render_y) * scale;
	pixel.z = 1;
	tmp = pixel;
	rot_vect[0] = vector(camera.rotation_matrix.right.x,
			camera.rotation_matrix.up.x, camera.rotation_matrix.foward.x);
	rot_vect[1] = vector(camera.rotation_matrix.right.y,
			camera.rotation_matrix.up.y, camera.rotation_matrix.foward.y);
	rot_vect[2] = vector(camera.rotation_matrix.right.z,
			camera.rotation_matrix.up.z, camera.rotation_matrix.foward.z);
	pixel.x = dot(tmp, rot_vect[0]);
	pixel.y = dot(tmp, rot_vect[1]);
	pixel.z = dot(tmp, rot_vect[2]);
	return (pixel);
}

void	ft_raycast(t_scene scene, t_env *env, t_camera camera, size_t i)
{
	int		x;
	int		y;
	size_t	index;
	t_ray	ray;

	y = 0;
	index = 0;
	ray.origin = camera.pos;
	while (y < scene.render_y)
	{
		x = 0;
		while (x < scene.render_x)
		{
			ray.direction = normalize(get_pixel_pos(scene, x, y, camera));
			ft_render_pixel(scene, &env->img[i], ray, index);
			index += 4;
			x++;
		}
		ft_printf("\rImage %d -> [%d%%]", i + 1, (y * 100) / scene.render_y);
		y++;
	}
	ft_printf("		\033[1;32mDone\033[0m\033[1m\n");
}

int		ft_render(t_scene scene, t_env *env)
{
	size_t		i;
	t_camera	camera;

	i = 0;
	while (i < scene.nb_of.cameras)
	{
		env->img[i].addr = mlx_new_image(env->mlx, env->size_x, env->size_y);
		env->img[i].buffer = mlx_get_data_addr(env->img[i].addr,
				&env->img[i].bpp, &env->img[i].line_size, &env->img[i].endian);
		camera.pos = scene.cameras.pos[i];
		camera.rot = scene.cameras.rot[i];
		camera.fov = scene.cameras.fov[i];
		camera.rotation_matrix = ft_look_at(camera.rot);
		ft_raycast(scene, env, camera, i);
		i++;
	}
	return (0);
}
