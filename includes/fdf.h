/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 21:42:49 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/23 21:50:46 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft.h"
#include "get_next_line.h"
#include "mlx.h"

typedef struct		s_data
{
	int				*data;
	size_t			size;
	struct s_data	*next;
}					t_data;

#endif
