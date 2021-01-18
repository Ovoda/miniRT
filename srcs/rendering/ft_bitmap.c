/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:04:30 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/16 14:29:03 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_get_header(t_header *header, t_scene scene)
{
	header->bmp_letters[0] = 'B';
	header->bmp_letters[1] = 'M';
	header->file_size = 54 + (scene.render_x * scene.render_y * 4);
	header->reserved_bytes = 0;
	header->buffer_offset = 54;
}

void	ft_get_info(t_info *info, t_scene scene)
{
	info->info_size = 40;
	info->width = scene.render_x;
	info->height = -scene.render_y;
	info->color_planes = 1;
	info->color_depth = 32;
	info->compression_method = 0;
	info->raw_data_size = scene.render_x * scene.render_y * 4;
	info->horizontal_res = 3780;
	info->vertical_res = 3780;
	info->color_table_entries = 0;
	info->important_colors = 0;
}

char	*ft_locate(char *name)
{
	int		i;
	int		tmp_i;
	char	*file_name;
	char	*tmp;

	i = 0;
	tmp_i = 0;
	while (name[i++])
		if (name[i] == '/')
			tmp_i = i + 1;
	file_name = ft_strdup(&name[tmp_i]);
	tmp = ft_strjoin(file_name, ".bmp");
	free(file_name);
	file_name = ft_strjoin("./images/", tmp);
	free(tmp);
	return (file_name);
}

void	ft_exit_save(t_scene *scene, t_env *env)
{
	size_t i;

	i = 0;
	while (i < scene->nb_of.cameras)
	{
		mlx_destroy_image(env->mlx, env->img[i].addr);
		i++;
	}
	mlx_destroy_display(env->mlx);
	ft_free(scene);
	free(env->img);
	free(env->mlx);
	exit(0);
}

int		ft_save(int argc, char **argv, t_scene *scene, t_env *env)
{
	t_header	header;
	t_info		info;
	int			fd;
	char		*file_name;

	ft_get_header(&header, *scene);
	ft_get_info(&info, *scene);
	file_name = NULL;
	if (argc == 3 && ft_strcmp(argv[2], "--save") == 0)
	{
		file_name = ft_locate(argv[1]);
		fd = open(file_name, O_WRONLY | O_TRUNC | O_CREAT, 0755);
		if (fd < 0)
			return (-1);
		write(fd, &header.bmp_letters[0], 2);
		write(fd, &header.file_size, 4);
		write(fd, &header.reserved_bytes, 4);
		write(fd, &header.buffer_offset, 4);
		write(fd, (char *)&info, 40);
		write(fd, &env->img->buffer[0], scene->render_x * scene->render_y * 4);
		ft_printf("Bitmap file created ! location: %s\n", file_name);
		free(file_name);
		ft_exit_save(scene, env);
	}
	return (0);
}
