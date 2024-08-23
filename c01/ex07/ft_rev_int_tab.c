/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a████ <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:52:33 by a████             #+#    #+#             */
/*   Updated: 2024/07/18 16:53:18 by a████            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	iteration_count;
	int	tmp;
	int	i;
	int	oposite_i;

	oposite_i = size - 1;
	if (size % 2 == 0)
	{
		iteration_count = size / 2;
	}
	else
	{
		iteration_count = (size - 1) / 2;
	}
	i = 0;
	while (i < iteration_count)
	{
		tmp = tab[i];
		tab[i] = tab[oposite_i];
		tab[oposite_i] = tmp;
		i++;
		oposite_i--;
	}
}
