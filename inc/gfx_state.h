/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_state.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 00:57:10 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/02 20:24:45 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_STATE_H
# define GFX_STATE_H

# include "gfx_primitive_types.h"
# include "gfx_keys.h"
# include "gfx_mouse.h"

struct s_gfx_image;

typedef struct	s_gfx_state
{
	void					*mlx_ptr;
	void					*win_ptr;
	void					*user_state;
	t_key_state				key_state;
	t_gfx_mouse				mouse_state;
	t_dimensions			dimensions;
	struct s_gfx_image		*buffer;
}				t_gfx_state;

/*
** Create a gfx state, given basic properties
** TODO: make an options type
** returns success
*/
int				gfx_mk_state(
		t_gfx_state *out,
		t_dimensions dimensions,
		char *window_title);

/*
** Free inner elements.
** Does not free pointer.
*/
int				gfx_free_state(
		t_gfx_state *state);

#endif
