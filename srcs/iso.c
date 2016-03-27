#include "libdraw.h"

void	iso_free(t_pix *ptr)
{
	if (ptr != NULL)
		free(ptr);
}

t_pix	iso_getcurp(t_data *data, int x, int y, int *z)
{
	t_pix	curp;

	*z = data.data[x];
	pcur.x = X0 + (XA * x) + (XA * y) + (ZA * z);
	pcur.y = Y0 + (YA * x) + (YA * y) + (ZA * z);
	pcur.color = 0.333 (float)(z / 10);
	return (curp);
}

void	isometrie(t_meta *meta, t_data data)
{
	t_pix	*prev_line;
	t_pix	*cur_line;
	int		y;
	int		z;

	prev_line = NULL;
	y = 0;
	while (data && ((cur_line = (t_pix*)malloc(sizeof(t_pix) * (data.size + 1)))))
	{
		cur_line[data.size] = 0;
		while (data.size > 0)
		{
			cur_line[data.size - 1] = iso_getcurp(*data, data.size - 1, y, &z);
			data.size--;
		}
		disp_x(cur_line);
		disp_y(cur_line, prev_line);
		iso_free(prev_line);
		prev_line = cur_line;
		data = *(data.next);
		y++;
	}
	iso_free(cur_line);
	iso_free(prev_line);
}
