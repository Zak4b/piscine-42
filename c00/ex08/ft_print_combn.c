/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a████ <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:20:42 by a████             #+#    #+#             */
/*   Updated: 2024/07/24 11:43:49 by a████            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_init_tab(char *tab, int n)
{
	char	i;

	i = 0;
	while (i < n)
	{
		tab[(int)i] = i;
		i++;
	}
}

// Return 1 in case of success
int	ft_increment_tab(char *comb_tab, int n, int index)
{
	int	state;

	if (comb_tab[index] < (9 - n + index + 1))
		comb_tab[index]++;
	else if (index > 0)
	{
		state = ft_increment_tab(comb_tab, n, index - 1);
		comb_tab[index] = comb_tab[index - 1] + 1;
		if (state == 0)
			return (0);
	}
	else
		return (0);
	return (1);
}

void	ft_print_tab(char *tab, int n)
{
	int		i;
	char	c;

	i = 0;
	while (i < n)
	{
		c = tab[i] + '0';
		write(1, &c, 1);
		i++;
	}
}

// 0 < n < 10
void	ft_print_combn(int n)
{
	char	comb_tab[9];
	int		i;

	i = 0;
	ft_init_tab(comb_tab, n);
	while (1)
	{
		if (i++ != 0)
			write(1, ", ", 2);
		ft_print_tab(comb_tab, n);
		if (!ft_increment_tab(comb_tab, n, n - 1))
			return ;
	}
}
