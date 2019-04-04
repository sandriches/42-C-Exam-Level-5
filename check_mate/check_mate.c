/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_mate.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: exam <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/19 13:04:53 by exam          #+#    #+#                 */
/*   Updated: 2019/03/19 15:26:26 by exam          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

int		ft_strlen(char *str)
{
	int x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}

int		ft_check_pawn(char **board, int y, int x, int len)
{
	if (y == 0)
		return (0);
	else if (x == 0)
	{
		if (board[y - 1][x + 1] == 'K')
			return (1);
	}
	else if (x == len - 1)
	{
		if (board[y - 1][x - 1] == 'K')
			return (1);
	}
	else
	{
		if (board[y - 1][x - 1] == 'K')
			return (1);
		if (board[y - 1][x + 1] == 'K')
			return (1);
	}
	return (0);
}

int		ft_check_rook(char **board, int y, int x, int len)
{
	int i;
	int j;

	i = x;
	j = y;
	while (i < len && board[j][i] != '\0')
	{
		if (board[j][i] == 'P' || board[j][i] == 'Q' || board[j][i] == 'B')
			break ;
		if (board[j][i] == 'R' && (j != y && i != x))
			break ;
		if (board[j][i] == 'K')
			return (1);
		i++;
	}
	i = x;
	while (i >= 0 && board[j][i] != '\0')
	{
		if (board[j][i] == 'P' || board[j][i] == 'Q' || board[j][i] == 'B')
			break ;
		if (board[j][i] == 'R' && (j != y && i != x))
			break ;
		if (board[j][i] == 'K')
			return (1);
		i--;
	}
	i = x;
	while (j < len && board[j][i] != '\0')
	{
		if (board[j][i] == 'P' || board[j][i] == 'Q' || board[j][i] == 'B')
			break ;
		if (board[j][i] == 'R' && (j != y && i != x))
			break ;
		if (board[j][i] == 'K')
			return (1);
		j++;
	}
	j = y;
	while (j >= 0 && board[j][i] != '\0')
	{
		if (board[j][i] == 'P' || board[j][i] == 'Q' || board[j][i] == 'B')
			break ;
		if (board[j][i] == 'R' && (j != y && i != x))
			break ;
		if (board[j][i] == 'K')
			return (1);
		j--;
	}
	return (0);
}

int		ft_check_bishop(char **board, int y, int x, int len)
{
	int i;
	int j;
	int ctr;
	int edge_x;
	int edge_y;

	edge_x = len - x;
	edge_y = len - y;
	i = x;
	j = y;
	ctr = 0;
	while (i < edge_x && j < edge_y && board[j][i] != '\0')
	{
		if (board[j][i] == 'P' || board[j][i] == 'R' || board[j][i] == 'Q')
			break ;
		if (board[j][i] == 'B' && (j != y && i != x))
			break ;
		if (board[j][i] == 'K')
			return (1);
		j++;
		i++;
	}
	i = x;
	j = y;
	while (i < edge_x && j >= 0 && board[j][i] != '\0')
	{
		if (board[j][i] == 'P' || board[j][i] == 'R' || board[j][i] == 'Q')
			break ;
		if (board[j][i] == 'B' && (j != y && i != x))
			break ;
		if (board[j][i] == 'K')
			return (1);
		j--;
		i++;
	}
	i = x;
	j = y;
	while (i >= 0 && j < edge_y && board[j][i] != '\0')
	{
		if (board[j][i] == 'P' || board[j][i] == 'R' || board[j][i] == 'Q')
			break ;
		if (board[j][i] == 'B' && (j != y && i != x))
			break ;
		if (board[j][i] == 'K')
			return (1);
		i--;
		j++;
	}
	i = x;
	j = y;
	while (i >= 0 && j >= 0 && board[j][i] != '\0')
	{
		if (board[j][i] == 'P' || board[j][i] == 'R' || board[j][i] == 'Q')
			break ;
		if (board[j][i] == 'B' && (j != y && i != x))
			break ;
		if (board[j][i] == 'K')
			return (1);
		i--;
		j--;
	}
	return (0);
}

int		ft_check_queen(char **board, int y, int x, int len)
{
	int i;
	int j;
	int ctr;
	int edge_x;
	int edge_y;

	edge_x = len - x;
	edge_y = len - y;
	i = x;
	j = y;
	ctr = 0;
	while (i < edge_x && j < edge_y && board[j][i] != '\0')
	{
		if (board[j][i] == 'P' || board[j][i] == 'R' || board[j][i] == 'B')
			break ;
		if (board[j][i] == 'Q' && (j != y && i != x))
			break ;
		if (board[j][i] == 'K')
			return (1);
		j++;
		i++;
	}
	i = x;
	j = y;
	while (i < edge_x && j >= 0 && board[j][i] != '\0')
	{
		if (board[j][i] == 'P' || board[j][i] == 'R' || board[j][i] == 'B')
			break ;
		if (board[j][i] == 'Q' && (j != y && i != x))
			break ;
		if (board[j][i] == 'K')
			return (1);
		j--;
		i++;
	}
	i = x;
	j = y;
	while (i >= 0 && j < edge_y && board[j][i] != '\0')
	{
		if (board[j][i] == 'P' || board[j][i] == 'R' || board[j][i] == 'B')
			break ;
		if (board[j][i] == 'Q' && (j != y && i != x))
			break ;
		if (board[j][i] == 'K')
			return (1);
		i--;
		j++;
	}
	i = x;
	j = y;
	while (i >= 0 && j >= 0 && board[j][i] != '\0')
	{
		if (board[j][i] == 'P' || board[j][i] == 'R' || board[j][i] == 'B')
			break ;
		if (board[j][i] == 'Q' && (j != y && i != x))
			break ;
		if (board[j][i] == 'K')
			return (1);
		i--;
		j--;
	}
	i = x;
	j = y;
	while (i < len && board[j][i] != '\0')
	{
		if (board[j][i] == 'P' || board[j][i] == 'R' || board[j][i] == 'B')
			break ;
		if (board[j][i] == 'Q' && (j != y && i != x))
			break ;
		if (board[j][i] == 'K')
			return (1);
		i++;
	}
	i = x;
	while (i >= 0 && board[j][i] != '\0')
	{
		if (board[j][i] == 'P' || board[j][i] == 'R' || board[j][i] == 'B')
			break ;
		if (board[j][i] == 'Q' && (j != y && i != x))
			break ;
		if (board[j][i] == 'K')
			return (1);
		i--;
	}
	i = x;
	while (j < len && board[j][i] != '\0')
	{
		if (board[j][i] == 'P' || board[j][i] == 'R' || board[j][i] == 'B')
			break ;
		if (board[j][i] == 'Q' && (j != y && i != x))
			break ;
		if (board[j][i] == 'K')
			return (1);
		j++;
	}
	j = y;
	while (j >= 0 && board[j][i] != '\0')
	{
		if (board[j][i] == 'P' || board[j][i] == 'R' || board[j][i] == 'B')
			break ;
		if (board[j][i] == 'Q' && (j != y && i != x))
			break ;
		if (board[j][i] == 'K')
			return (1);
		j--;
	}
	return (0);
}

int		ft_solution(char **board, int len)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while (y < len)
	{
		while (board[y][x] != '\0' && x < len)
		{
			if (board[y][x] == 'R')
			{
				if (ft_check_rook(board, y, x, len) == 1)
					return (1);
			}
			if (board[y][x] == 'B')
			{
				if (ft_check_bishop(board, y, x, len) == 1)
					return (1);
			}
			if (board[y][x] == 'P')
			{
				if (ft_check_pawn(board, y, x, len) == 1)
					return (1);
			}
			if (board[y][x] == 'Q')
			{
				if (ft_check_queen(board, y, x, len) == 1)
					return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

char	*ft_strcpy(char *src)
{
	int		x;
	int		len;
	char	*rtn;

	x = 0;
	len = ft_strlen(src);
	rtn = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	while (src[x] != '\0' && x < len)
	{
		rtn[x] = src[x];
		x++;
	}
	rtn[x] = '\0';
	return (rtn);
}

int		main(int argc, char **argv)
{
	char	**board;
	int		x;
	int		y;

	x = 0;
	y = 1;
	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	board = (char **)malloc(sizeof(char *) * argc + 1);
	while (y < argc)
	{
		board[x] = ft_strcpy(argv[y]);
		x++;
		y++;
	}
	if (ft_solution(board, argc - 1) == 1)
		write(1, "Success\n", 8);
	else
		write(1, "Fail\n", 5);
	return (1);
}
