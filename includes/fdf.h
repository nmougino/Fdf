/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 21:42:49 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/31 18:23:32 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "libdraw.h"
# include "get_next_line.h"
# include "mlx.h"

# define WINX 1980
# define WINY 1080

# define X0 50
# define Y0 500
# define X0U 10
# define X0U 10

# define XA 15
# define YA 5
# define ZA 1

# define K_ESC 53
# define K_SPA 49
# define K_UP 126
# define K_DO 125
# define K_LE 123
# define K_RI 124
# define K_Q 12
# define K_C 8
# define K_P 35
# define K_B 11
# define K_H 4
# define K_J 38
# define K_F 3
# define K_G 5
# define K_MAJG 0x4b
# define K_PLUS 69
# define K_MIN 78
# define K_DIV 75
# define K_MUL 67
# define K_CHEVG 43
# define K_CHEVD 47


typedef struct		s_data
{
	int				*data;
	int				size;
	char			*file;
	struct s_data	*next;
}					t_data;

typedef struct		s_meta
{
	void			*mlx;
	void			*win;
	t_img			*img;
	int				ktab[127];
	int				arg;
	t_data			**data;
	t_px			pto;
	t_px			pta;
	t_px			ptaa;
	int				coefz;
	t_px			graph;
	int				prevsize;
	char			istheredata;
	int				argc;
}					t_meta;

void				datafree(t_data **fst);

void				err_open(char *file);
void				err_nodata(char *file);
void				err_input(void);

t_data				*parser(char *file);

void				iso(t_meta *meta);

void				init_hooks(t_meta *meta);

void				ctrl_exit(t_meta *meta);

t_meta				*meta_init(int argc, char **argv);
void				meta_reset(t_meta *meta);

void				ctrl_trans_ud(t_meta *meta, int p);
void				ctrl_trans_lr(t_meta *meta, int p);

void				ctrl_rot_lr(t_meta *meta, int p);

void				ctrl_npfile(t_meta *meta, int p);

void				ctrl_hight(t_meta *meta, int p);

void				ctrl_zoom(t_meta *meta, int p);

#endif
