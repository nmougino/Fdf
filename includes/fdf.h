/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 21:42:49 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/27 05:56:07 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "libdraw.h"
# include "get_next_line.h"
# include "mlx.h"

# define X0 50
# define Y0 500

# define XA 30
# define YA 10
# define ZA 1

typedef struct		s_meta
{
	void			*mlx;
	void			*win;
	t_img			*img;
	int				arg;
}					t_meta;

typedef struct		s_data
{
	int				*data;
	size_t			size;
	char			*file;
	struct s_data	*next;
}					t_data;

void				datafree(t_data **fst);

void				err_open(int i);
void				err_nodata(int i);

t_data				*parser(char *file);

void				iso(t_meta *meta, t_data *data);

#endif
