/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a████ <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:02:48 by a████             #+#    #+#             */
/*   Updated: 2024/07/29 14:02:49 by a████            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
int	can_place(int index, int grid[100])
{
	int	i;
	int	col;
	int	row;

	col = index % 10;
	row = index / 4;
	i = row * 10;
	while (i / 10 == row)
		if (grid[i++] == 1)
			return (0);
	i = col;
	while (i < 100)
	{
		if (grid[i] == 1)
			return (0);
		i += 10;
	}
	i = 0; // position haute de la diag ??
	while ('??') // comparer col avant et apres i += 11;
	{
		if (grid[i] == 1)
			return (0);
		i += 11;
	}
	return (10);
}

int rec(int start_index, int count, int grid[100])
{
	int index;

	while (!can_place(index, grid))
		index++;
	if ()
	return (index);
}

int ft_ten_queens_puzzle(void)
{
	int grid[100];
	int i;

	i = 0;
	while (i < 100)
		grid[i++] = 0;
	rec(0, 0, grid);
	return (0);
}
*/