/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rs██████ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:24:19 by rs██████          #+#    #+#             */
/*   Updated: 2024/07/21 15:41:43 by rs██████         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush00(int x_len, int y_len)
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
			if ((y == 0 || y == y_len) && (x == 0 || x == x_len))
				ft_putchar('o');
			else if (x == 0 || x == x_len)
				ft_putchar('|');
			else if (y == 0 || y == y_len)
				ft_putchar('-');
			else
				ft_putchar(' ');
			x++;
		}
		y++;
		ft_putchar('\n');
	}
}
