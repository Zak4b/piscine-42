/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a████ <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:43:59 by a████             #+#    #+#             */
/*   Updated: 2024/07/28 14:44:00 by a████            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "views.h"

void	get_col_views(int index, int views[16], int dest[2])
{
	dest[0] = views[index];
	dest[1] = views[index + 4];
}

void	get_row_views(int index, int views[16], int dest[2])
{
	dest[0] = views[index + 8];
	dest[1] = views[index + 8 + 4];
}
