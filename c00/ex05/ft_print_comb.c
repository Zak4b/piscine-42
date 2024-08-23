/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a████ <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:17:21 by a████             #+#    #+#             */
/*   Updated: 2024/07/17 15:06:32 by a████            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_separator(char comb[3])
{
	if (! (comb[0] == '0' && comb[1] == '1' && comb[2] == '2'))
	{
		write(1, ", ", 2);
	}
}

void	ft_write_comb(char comb[3])
{
	ft_print_separator(comb);
	write(1, comb, 3);
}

void	ft_print_comb(void)
{
	char	comb[3];

	comb[0] = '0';
	while (comb[0] <= '9')
	{
		comb[1] = comb[0] + 1;
		while (comb[1] <= '9')
		{
			comb[2] = comb[1] + 1;
			while (comb[2] <= '9')
			{
				ft_write_comb(comb);
				comb[2]++;
			}
			comb[1]++;
		}
		comb[0]++;
	}
}
