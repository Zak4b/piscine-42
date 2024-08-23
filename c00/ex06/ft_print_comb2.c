/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a████ <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:25:31 by a████             #+#    #+#             */
/*   Updated: 2024/07/17 15:35:23 by a████            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_separator(int num_1, int num_2)
{
	if (! (num_1 == 0 && num_2 == 1))
	{
		write(1, ", ", 2);
	}
}

void	ft_write_comb(int num_1, int num_2)
{
	char	string[5];

	string[0] = num_1 / 10 + '0';
	string[1] = num_1 % 10 + '0';
	string[2] = ' ';
	string[3] = num_2 / 10 + '0';
	string[4] = num_2 % 10 + '0';
	ft_print_separator(num_1, num_2);
	write(1, string, 5);
}

void	ft_print_comb2(void)
{
	int		num_1;
	int		num_2;

	num_1 = 0;
	while (num_1 <= 99)
	{
		num_2 = num_1 + 1;
		while (num_2 <= 99)
		{
			ft_write_comb(num_1, num_2);
			num_2++;
		}
		num_1++;
	}
}
