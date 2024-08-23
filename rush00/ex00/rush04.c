/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rs██████ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:35:00 by rs██████          #+#    #+#             */
/*   Updated: 2024/07/21 15:39:50 by rs██████         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush04(int x_len, int y_len)
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
			if ((x == 0 && y == 0) || (x == x_len && y == y_len
					&& x_len != 0 && y_len != 0))
				ft_putchar('A');
			else if ((x == 0 && y == y_len) || (x == x_len && y == 0))
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
