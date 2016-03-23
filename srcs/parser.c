/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 00:58:05 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/23 18:27:24 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_data	*newelem(void)
{
	t_data	*ans;

	ans = (t_data*)memalloc(sizeof(t_data));
	if (ans)
	{
		ans->size = 0;
		ans->next = NULL;
		ans->data = NULL;
	}
	return (ans);
}

static void		getdata(int *data, char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		data[i] = atoi(tmp[i]);
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
		tmp = strsplit(line, ' ');
		while (tmp[ans->size])
			(ans->size)++;
		ans->data = (int*)memalloc(sizeof(int) * ans->size);
		getdata(ans->data, tmp);
	}
	return (ans);
}

t_data	*parser(int fd)
{
	t_data	*fst;
	t_data	*cur;

	fst = extract(fd);
	cur = fst;
	while (cur)
	{
		cur->next = extract(fd);
		cur = cur->next;
	}
	return (fst);
}
