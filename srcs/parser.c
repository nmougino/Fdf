/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 00:58:05 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/31 16:46:21 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_data	*newelem(void)
{
	t_data	*ans;

	ans = (t_data*)ft_memalloc(sizeof(t_data));
	if (ans)
	{
		ans->size = 0;
		ans->next = NULL;
		ans->data = NULL;
	}
	return (ans);
}

static void		parser_getdata(int *data, char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		data[i] = ft_atoi(tmp[i]);
		free(tmp[i]);
		tmp[i] = NULL;
		i++;
	}
}

static t_data	*extract(fd)
{
	t_data	*ans;
	char	*line;
	char	**tmp;
	size_t	i;

	ans = NULL;
	i = 0;
	if (get_next_line(fd, &line) > 0 && (ans = newelem()))
	{
		tmp = ft_strsplit(line, ' ');
		while (tmp[ans->size])
			(ans->size)++;
		ans->data = (int*)ft_memalloc(sizeof(int) * ans->size);
		parser_getdata(ans->data, tmp);
	}
	return (ans);
}

t_data			*parser(char *file)
{
	t_data	*fst;
	t_data	*cur;
	int		fd;

	fst = NULL;
	cur = NULL;
	if ((fd = open(file, O_RDONLY)) > 0)
	{
		if ((fst = extract(fd)))
		{
			fst->file = ft_strdup(file);
			cur = fst;
			while (cur)
			{
				cur->next = extract(fd);
				cur = cur->next;
			}
		}
		else
			err_nodata(file);
		close(fd);
	}
	else
		err_open(file);
	return (fst);
}
