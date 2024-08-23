/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a████ <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:41:16 by a████             #+#    #+#             */
/*   Updated: 2024/07/28 14:41:18 by a████            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "views.h"

int		print_error(int return_value);

int		solve(int grid[4][4], int views[16]);

void	print_gird(int grid[4][4]);

void	init_grid(int grid[4][4]);

int	handle_arg(char *arg_string, int dest[16])
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (arg_string[i] && count <= 16)
	{
		if (i % 2 == 0)
		{
			if (arg_string[i] < '1' || arg_string[i] > '4')
				return (0);
			else
			{
				dest[i / 2] = arg_string[i] - '0';
				count++;
			}
		}
		else if (i % 2 == 1 && arg_string[i] != ' ')
			return (0);
		i++;
	}
	return (count == 16);
}

int	main(int argc, char **argv)
{
	int	grid[4][4];
	int	views[16];

	init_grid(grid);
	if (argc != 2 || !handle_arg(argv[1], views))
		return (print_error(1));
	if (solve(grid, views))
		print_gird(grid);
	else
		print_error(1);
}
