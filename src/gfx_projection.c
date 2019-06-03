/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_projection.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/05 13:39:28 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/03 18:18:00 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gfx_projection.h"
#include <math.h>

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

t_vec3		gfx_rotation_x(t_vec3 v, double theta)
{
	t_vec3 after_rot;

	after_rot.x = v.x;
	after_rot.y = cos(theta) * v.y + sin(theta) * v.z;
	after_rot.z = -sin(theta) * v.y + cos(theta) * v.z;
	return (after_rot);
}

t_vec3	gfx_rotation_y(t_vec3 v, double theta)
{
	t_vec3 after_rot;

	after_rot.x = cos(theta) * v.x + sin(theta) * v.z;
	after_rot.y = v.y;
	after_rot.z = -sin(theta) * v.x + cos(theta) * v.z;
	return (after_rot);
}

t_vec3	gfx_rotation_z(t_vec3 v, double theta)
{
	t_vec3 after_rot;

	after_rot.x = cos(theta) * v.x - sin(theta) * v.y;
	after_rot.y = sin(theta) * v.x + cos(theta) * v.y;
	after_rot.z = v.z;
	return (after_rot);
}

t_vec3	gfx_rotation(t_vec3 v, t_vec3 thetas)
{
	return (gfx_rotation_x(gfx_rotation_y(
		gfx_rotation_z(v, thetas.z), thetas.y), thetas.x));
}
