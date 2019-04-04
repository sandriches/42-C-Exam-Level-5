/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   biggest_pal.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: exam <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/02 14:06:03 by exam          #+#    #+#                 */
/*   Updated: 2019/04/02 14:46:19 by exam          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "biggest_pal.h"

void	ft_putstr(char *str)
{
	int x;

	x = 0;
	while (str[x] != '\0')
	{
		write(1, &str[x], 1);
		x++;
	}
}

void	ft_biggest_pal(char *str)
{
	int x;
	int y;
	int prev_y;
	int pal_pos;
	int type;
	int start;

	x = 0;
	y = 0;
	prev_y = 0;
	pal_pos = 0;
	start = 0;
	while (str[x] != '\0')
	{
		while (str[x + y] && str[x - y] && str[x + y] == str[x - y])
			y++;
		if (y >= prev_y)
		{
			pal_pos = x;
			prev_y = y;
			type = 1;
		}
		y = 0;
		x++;
	}
	x = 0;
	y = 0;
	while (str[x] != '\0')
	{
		while (str[x + y + 1] && str[x - y] && str[x + y + 1] == str[x - y])
			y++;
		if (y >= prev_y)
		{
			pal_pos = x;
			prev_y = y;
			type = 2;
		}
		y = 0;
		x++;
	}
	y = 0;
	if (type == 1)
	{
		start = pal_pos - (prev_y - 1);
		y = pal_pos + (prev_y - 1);
	}
	else if (type == 2)
	{
		start = pal_pos - (prev_y - 1);
		y = pal_pos + prev_y;
	}
	x = 0;
	y -= start;
	while (x <= y)
	{
		write(1, &str[start], 1);
		start++;
		x++;
	}
	ft_putstr("\n");
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("\n");
		return (0);
	}
	ft_biggest_pal(argv[1]);
	return (1);
}
