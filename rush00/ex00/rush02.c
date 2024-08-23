/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rs██████ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:35:06 by a████             #+#    #+#             */
/*   Updated: 2024/07/21 15:39:41 by rs██████         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush02(int x_len, int y_len)
{
	int	x;
	int	y;

	x_len--;
	y_len--;
	y = 0;
	while (y <= y_len)
	{
		x = 0;
		while (x <= x_len)
		{
			if (y == 0 && (x == 0 || x == x_len))
				ft_putchar('A');
			else if (y == y_len && (x == 0 || x == x_len))
				ft_putchar('C');
			else if (y == 0 || y == y_len || x == 0 || x == x_len)
				ft_putchar('B');
			else
				ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
