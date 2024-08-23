/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a████ <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:29:51 by a████             #+#    #+#             */
/*   Updated: 2024/07/27 16:29:53 by a████            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillers.h"
#include "views.h"
#include "utils.h"
#include "grid.h"

void	set_last_of_type(int value, int grid[4][4])
{
	int	i;
	int	j;
	int	pos[2][4];

	init_array(pos);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (grid[i][j] == value)
			{
				pos[0][i] = 1;
				pos[1][j] = 1;
			}
		}
	}
	i = 0;
	while (pos[0][i] != 0 && i < 4)
		i++;
	j = 0;
	while (pos[1][j] != 0 && j < 4)
		j++;
	set(i, j, value, grid);
}

void	fill_row(int row_index, int grid[4][4])
{
	int	values;
	int	i;
	int	target;

	i = 0;
	values = 0;
	while (i < 4)
	{
		values += grid[row_index][i];
		if (grid[row_index][i] == 0)
			target = i;
		i++;
	}
	if (grid[row_index][target] == 0)
		set(row_index, target, 10 - values, grid);
}

void	fill_col(int col_index, int grid[4][4])
{
	int	values;
	int	i;
	int	target;

	i = 0;
	values = 0;
	while (i < 4)
	{
		values += grid[i][col_index];
		if (grid[i][col_index] == 0)
			target = i;
		i++;
	}
	if (grid[target][col_index] == 0)
		set(target, col_index, 10 - values, grid);
}

void	check_fillable_row(int grid[4][4])
{
	int	i;
	int	j;
	int	count_row;
	int	count_col;

	i = 0;
	while (i < 4)
	{
		j = 0;
		count_col = 0;
		count_row = 0;
		while (j < 4)
		{
			if (grid[i][j] == 0)
				count_row++;
			if (grid[j][i] == 0)
				count_col++;
			j++;
		}
		if (count_row == 1)
			fill_row(i, grid);
		if (count_col == 1)
			fill_col(i, grid);
		i++;
	}
}

int	solve(int grid[4][4], int views[16])
{
	int	i;
	int	j;

	fill_1(grid, views);
	fill_1_4(grid, views);
	fill_2_3(grid, views);
	fill_1_2(grid, views);
	i = 0;
	while (i < 3)
	{
		if (count_value_in_grid(4, grid))
			set_last_of_type(4, grid);
		if (count_value_in_grid(3, grid))
			set_last_of_type(3, grid);
		j = 0;
		while (j++ < 5)
			check_fillable_row(grid);
		i++;
	}
	if (count_value_in_grid(0, grid) > 1)
		return (0);
	else
		return (1);
}
