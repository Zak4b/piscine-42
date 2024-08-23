/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a████ <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:32:58 by a████             #+#    #+#             */
/*   Updated: 2024/07/28 14:33:00 by a████            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillers.h"
#include "views.h"
#include "grid.h"

void	fill_1(int grid[4][4], int views[16])
{
	int	i;
	int	i_views[2];

	i = 0;
	while (i < 4)
	{
		get_row_views(i, views, i_views);
		if (i_views[0] == 1)
			set_row(i, "4---", grid);
		else if (i_views[1] == 1)
			set_row(i, "---4", grid);
		get_col_views(i, views, i_views);
		if (i_views[0] == 1)
			set_col(i, "4---", grid);
		else if (i_views[1] == 1)
			set_col(i, "---4", grid);
		i++;
	}
}

void	fill_1_4(int grid[4][4], int views[16])
{
	int	i;
	int	i_views[2];

	i = 0;
	while (i < 4)
	{
		get_row_views(i, views, i_views);
		if (i_views[0] == 4)
			set_row(i, "1234", grid);
		else if (i_views[1] == 4)
			set_row(i, "4321", grid);
		get_col_views(i, views, i_views);
		if (i_views[0] == 4)
			set_col(i, "1234", grid);
		else if (i_views[1] == 4)
			set_col(i, "4321", grid);
		i++;
	}
}

void	fill_2_3(int grid[4][4], int views[16])
{
	int	i;
	int	i_views[2];

	i = 0;
	while (i < 4)
	{
		get_row_views(i, views, i_views);
		if (i_views[0] == 2 && i_views[1] == 3)
			set(i, 1, 4, grid);
		else if (i_views[0] == 3 && i_views[1] == 2)
			set(i, 2, 4, grid);
		get_col_views(i, views, i_views);
		if (i_views[0] == 2 && i_views[1] == 3)
			set(1, i, 4, grid);
		else if (i_views[0] == 3 && i_views[1] == 2)
			set(2, i, 4, grid);
		i++;
	}
}

void	fill_1_2(int grid[4][4], int views[16])
{
	int	i;
	int	i_views[2];

	i = 0;
	while (i < 4)
	{
		get_row_views(i, views, i_views);
		if (i_views[0] == 1 && i_views[1] == 2)
			set_row(i, "4--3", grid);
		else if (i_views[0] == 2 && i_views[1] == 1)
			set_row(i, "3--4", grid);
		get_col_views(i, views, i_views);
		if (i_views[0] == 1 && i_views[1] == 2)
			set_col(i, "4--3", grid);
		else if (i_views[0] == 2 && i_views[1] == 1)
			set_col(i, "3--4", grid);
		i++;
	}
}
