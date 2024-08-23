/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a████ <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:32:27 by a████             #+#    #+#             */
/*   Updated: 2024/07/28 14:32:28 by a████            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_H
# define GRID_H

void	init_grid(int grid[4][4]);

void	set(int row_index, int col_index, int value, int grid[4][4]);

void	set_row(int index, char *values, int grid[4][4]);

void	set_col(int index, char *values, int grid[4][4]);

int		count_value_in_grid(int value, int grid[4][4]);

#endif
