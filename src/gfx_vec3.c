/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_vec3.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 19:10:30 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/05 14:29:18 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>

t_vec3	mk_vec3(double x, double y, double z)
{
	t_vec3 v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec3	add_vec3(t_vec3 a, t_vec3 b)
{
	t_vec3 n;

	n.x = a.x + b.x;
	n.y = a.y + b.y;
	n.z = a.z + b.z;
	return (n);
}

t_vec3	sub_vec3(t_vec3 a, t_vec3 b)
{
	t_vec3 n;

	n.x = a.x - b.x;
	n.y = a.y - b.y;
	n.z = a.z - b.z;
	return (n);
}

t_vec3	negate_vec3(t_vec3 a)
{
	t_vec3 n;

	n.x = -a.x;
	n.y = -a.y;
	n.z = -a.z;
	return (n);
}
