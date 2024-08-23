/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a████ <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:32:33 by a████             #+#    #+#             */
/*   Updated: 2024/07/28 14:32:42 by a████            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

void	init_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	set(int row_index, int col_index, int value, int grid[4][4])
{
	grid[row_index][col_index] = value;
}

void	set_row(int index, char *values, int grid[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (values[i] >= '0' && values[i] <= '9')
			grid[index][i] = values[i] - '0';
		i++;
	}
}

void	set_col(int index, char *values, int grid[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (values[i] >= '0' && values[i] <= '9')
			grid[i][index] = values[i] - '0';
		i++;
	}
}

int	count_value_in_grid(int value, int grid[4][4])
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (grid[i][j] == value)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
