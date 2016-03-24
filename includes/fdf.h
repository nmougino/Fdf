/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 21:42:49 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/24 17:45:02 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "libdraw.h"
# include "get_next_line.h"
# include "mlx.h"

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

#endif
