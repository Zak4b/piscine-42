/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rs██████ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:03:14 by rs██████          #+#    #+#             */
/*   Updated: 2024/07/21 15:39:40 by rs██████         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush03(int x_len, int y_len)
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
			if (x == 0 && (y == 0 || y == y_len))
				ft_putchar('A');
			else if (x == x_len && (y == 0 || y == y_len))
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
