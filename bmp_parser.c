/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 10:09:51 by notraore          #+#    #+#             */
/*   Updated: 2019/03/18 10:09:51 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int					test_file(FILE *file, unsigned char *header)
{
	if (fread(header, 1, 54, file) != 54)
		ft_kill("not ok");
	if (header[0] != 'B' || header[1] != 'M')
		ft_kill("Not a bmp file");
	return (1);
}

unsigned char		*read_bmp(FILE *file, unsigned char *header, t_glenv *env)
{
	int				width;
	int				height;
	unsigned char	*data;
	int				image_size;
	int				data_pos;

	data_pos = *(int*)&(header[0x0A]);
	image_size = *(int*)&(header[0x22]);
	width = *(int*)&(header[0x12]);
	height = *(int*)&(header[0x16]);
	env->tex_width = width;
	env->tex_height = height;
	if (image_size == 0)
		image_size = width * height * 3;
	if (data_pos == 0)
		data_pos = 54;
	data = (unsigned char *)malloc(image_size * sizeof(unsigned char));
	fread(data, 1, image_size, file);
	fclose(file);
	return (data);
}

unsigned char		*parse_bmp(char const *pathname, t_glenv *env)
{
	FILE			*file;
	unsigned char	header[54];

	file = fopen(pathname, "rb");
	if (!file)
		ft_kill("Image impossible to open.");
	if (!test_file(file, header))
		ft_kill("killed");
	return (read_bmp(file, header, env));
}
