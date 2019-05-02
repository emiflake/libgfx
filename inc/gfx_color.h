/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_color.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 00:56:50 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/02 20:29:43 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_COLOR_H
# define GFX_COLOR_H

# include <mlx.h>

typedef struct	s_rgb
{
	int r;
	int g;
	int b;
}				t_rgb;

typedef struct	s_hsl
{
	int		h;
	double	s;
	double	l;
}				t_hsl;

typedef struct	s_gradient
{
	int start;
	int end;
}				t_gradient;

/*
** Convert RGB color to int32 color
*/
int				gfx_color(int r, int g, int b, int a);

t_rgb			gfx_hsl2rgb(t_hsl hsl);
t_hsl			gfx_rgb2hsl(t_rgb rgb);
t_rgb			mk_rgb(int r, int g, int b);
t_hsl			mk_hsl(int h, double s, double l);

int				gfx_color_from_rgb(t_rgb rgb);

#endif
