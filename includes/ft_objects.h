/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objects.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:23:44 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/16 13:43:36 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OBJECTS_H
# define FT_OBJECTS_H
# define CAM 0
# define LIGHT 1
# define SPHERE 2
# define PLANE 3
# define SQUARE 4
# define CYLINDER 5
# define TRIANGLE 6
# include "minirt.h"

typedef struct	s_vect
{
	double	x;
	double	y;
	double	z;
}				t_vect;

typedef struct	s_matrix
{
	t_vect right;
	t_vect up;
	t_vect foward;
}				t_matrix;

typedef	struct	s_camera
{
	t_vect		pos;
	t_vect		rot;
	double		fov;
	t_matrix	rotation_matrix;
	int			id;
}				t_camera;

typedef	struct	s_camera_list
{
	t_vect		*pos;
	t_vect		*rot;
	double		*fov;
	int			*id;
}				t_camera_list;

typedef struct	s_light
{
	t_vect	pos;
	t_vect	dir;
	double	distance;
	double	ratio;
	int		rgba;
	int		id;
}				t_light;

typedef struct	s_light_list
{
	t_vect	*pos;
	t_vect	*dir;
	double	*distance;
	double	*ratio;
	int		*rgba;
	int		*id;
}				t_light_list;

typedef	struct	s_obj
{
	int			id;
	int			type;
	t_vect		pos;
	t_vect		rot;
	double		diameter;
	double		height;
	int			rgba;
	t_vect		points[3];
}				t_obj;

typedef	struct	s_obj_list
{
	int			*id;
	int			*type;
	t_vect		*pos;
	t_vect		*rot;
	double		*diameter;
	double		*height;
	int			*rgba;
	t_vect		*points[3];
}				t_obj_list;

typedef	struct	s_nb_obj
{
	size_t		cameras;
	size_t		lights;
	size_t		spheres;
	size_t		cylinders;
	size_t		planes;
	size_t		triangles;
	size_t		squares;
}				t_nb_obj;

typedef struct	s_pack
{
	t_vect pos;
	t_vect rot;
	double diameter;
	double height;
}				t_pack;

typedef struct	s_scene
{
	int				render_x;
	int				render_y;
	double			aspect_ratio;
	double			ambient_light_ratio;
	int				ambient_light_rgb;
	t_camera_list	cameras;
	t_light_list	lights;
	t_obj_list		spheres;
	t_obj_list		planes;
	t_obj_list		triangles;
	t_obj_list		squares;
	t_obj_list		cylinders;
	t_nb_obj		nb_of;
}				t_scene;

typedef struct	s_img
{
	void		*addr;
	char		*buffer;
	int			bpp;
	int			line_size;
	int			endian;
}				t_img;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			size_x;
	int			size_y;
	t_img		*img;
}				t_env;

typedef struct	s_ray
{
	t_vect		origin;
	t_vect		direction;
}				t_ray;

typedef struct	s_inter_point
{
	double		t;
	double		t1;
	double		t2;
	t_vect		coord;
	t_vect		normal;
	int			hit;
	double		pixel_intensity;
	int			color;
	int			id;
	int			type;
	t_ray		ray;
}				t_inter_point;

typedef struct	s_phong
{
	double		diffuse;
	double		specular;
}				t_phong;

typedef struct	s_params
{
	int			i;
	t_env		*env;
	int			nb_cam;
	t_scene		*scene;
}				t_params;

typedef	struct	s_color_coef
{
	double		r;
	double		g;
	double		b;
	int			is_in_shadow;
}				t_color_coef;

typedef struct	s_header {
	char			bmp_letters[2];
	unsigned int	file_size;
	unsigned int	reserved_bytes;
	unsigned int	buffer_offset;
}				t_header;

typedef struct	s_info {
	unsigned int	info_size;
	int				width;
	int				height;
	unsigned short	color_planes;
	unsigned short	color_depth;
	unsigned int	compression_method;
	unsigned int	raw_data_size;
	int				horizontal_res;
	int				vertical_res;
	unsigned int	color_table_entries;
	unsigned int	important_colors;
}				t_info;

typedef struct	s_delta
{
	double		a;
	double		b;
	double		c;
	double		delta;
}				t_delta;

#endif
