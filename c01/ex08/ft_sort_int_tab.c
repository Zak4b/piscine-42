/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a████ <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:57:34 by a████             #+#    #+#             */
/*   Updated: 2024/07/18 19:28:31 by a████            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

int	ft_tab_is_sorted(int *tab, int size)
{
	int	j;

	j = 0;
	while (j < size - 1)
	{
		if (tab[j] > tab[j + 1])
		{
			return (0);
		}
		j++;
	}
	return (1);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap(&tab[i], &tab[i + 1]);
			}
			i++;
		}
		if (ft_tab_is_sorted(tab, size))
			return ;
	}
}
