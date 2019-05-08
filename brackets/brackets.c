/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   brackets.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: exam <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/07 13:04:42 by exam          #+#    #+#                 */
/*   Updated: 2019/05/07 13:35:30 by exam          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "brackets.h"

int		do_string(char *str)
{
	int x;
	int square_count;
	int curly_count;
	int bracket_count;
	int y;

	square_count = 0;
	curly_count = 0;
	bracket_count = 0;
	x = 0;
	y = 0;
	while (str[x] != '\0')
	{
		if (str[x] == '[')
			square_count++;
		else if (str[x] == '{')
			curly_count++;
		else if (str[x] == '(')
			bracket_count++;
		else if (str[x] == ']')
			square_count--;
		else if (str[x] == '}')
			curly_count--;
		else if (str[x] == ')')
			bracket_count--;
		x++;
	}
	x = 0;
	if (bracket_count != 0 || square_count != 0 || curly_count != 0)
		return (0);
	x = 0;
	while (str[x] != '\0')
	{
		if (str[x] == ')')
		{
			y = x;
			while (y >= 0)
			{
				if (str[y] == '[' || str[y] == '{')
					return (0);
				if (str[y] == '(')
				{
					str[y] = ' ';
					str[y] = ' ';
					break ;
				}
				y--;
			}
			if (y == -1)
				return (0);
		}
		else if (str[x] == ']')
		{
			y = x;
			while (y >= 0)
			{
				if (str[y] == '(' || str[y] == '{')
					return (0);
				if (str[y] == '[')
				{
					str[y] = ' ';
					str[y] = ' ';
					break ;
				}
				y--;
			}
			if (y == -1)
				return (0);
		}
		if (str[x] == '}')
		{
			y = x;
			while (y >= 0)
			{
				if (str[y] == '[' || str[y] == '(')
					return (0);
				if (str[y] == '{')
				{
					str[y] = ' ';
					str[y] = ' ';
					break ;
				}
				y--;
			}
			if (y == -1)
				return (0);
		}
		x++;
	}
	return (1);
}

void	do_brackets(char **args)
{
	int x;
	int result;

	result = 0;
	x = 1;
	while (args[x])
	{
		result = do_string(args[x]);
		if (result == 1)
			write(1, "OK\n", 3);
		else if (result == 0)
			write(1, "Error\n", 6);
		x++;
	}
}

int		main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	do_brackets(argv);
	return (0);
}
