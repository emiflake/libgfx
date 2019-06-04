/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_matrix_future.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 19:02:21 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/03 19:02:37 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gfx_projection.h"
#define MAT_X 0
#define MAT_Y 1
#define MAT_Z 2

void		gfx_rotation_matrix_x(t_matrix m, double theta)
{
	m[MAT_X][MAT_X] += 1;
	m[MAT_X][MAT_Y] += 0;
	m[MAT_X][MAT_Z] += 0;
	m[MAT_Y][MAT_X] += 0;
	m[MAT_Y][MAT_Y] += cos(theta);
	m[MAT_Y][MAT_Z] += sin(theta);
	m[MAT_Z][MAT_X] += 0;
	m[MAT_Z][MAT_Y] += -sin(theta);
	m[MAT_Z][MAT_Z] += cos(theta);
}

void		gfx_rotation_matrix_y(t_matrix m, double theta)
{
	m[MAT_X][MAT_X] += cos(theta);
	m[MAT_X][MAT_Y] += 0;
	m[MAT_X][MAT_Z] += sin(theta);
	m[MAT_Y][MAT_X] += 0;
	m[MAT_Y][MAT_Y] += 1;
	m[MAT_Y][MAT_Z] += 0;
	m[MAT_Z][MAT_X] += -sin(theta);
	m[MAT_Z][MAT_Y] += 0;
	m[MAT_Z][MAT_Z] += cos(theta);
}

void		gfx_rotation_matrix_z(t_matrix m, double theta)
{
	m[MAT_X][MAT_X] += cos(theta);
	m[MAT_X][MAT_Y] += -sin(theta);
	m[MAT_X][MAT_Z] += 0;
	m[MAT_Y][MAT_X] += sin(theta);
	m[MAT_Y][MAT_Y] += cos(theta);
	m[MAT_Y][MAT_Z] += 0;
	m[MAT_Z][MAT_X] += 0;
	m[MAT_Z][MAT_Y] += 0;
	m[MAT_Z][MAT_Z] += 1;
}

t_vec3		gfx_rotate(t_matrix m, t_vec3 v)
{
	t_vec3 n;

	n.x = v.x * m[MAT_X][MAT_X]
		+ v.y * m[MAT_X][MAT_Y]
		+ v.z * m[MAT_X][MAT_Z];
	n.y = v.x * m[MAT_Y][MAT_X]
		+ v.y * m[MAT_Y][MAT_Y]
		+ v.z * m[MAT_Y][MAT_Z];
	n.z = v.x * m[MAT_Z][MAT_X]
		+ v.y * m[MAT_Z][MAT_Y]
		+ v.z * m[MAT_Z][MAT_Z];
	return (n);
}
